import scala.io.StdIn.readLine
import scala.reflect.ClassTag

trait Monoid[T] {
  val combineFn: (T, T) => T

  def zero: T
}

trait LazyOperation[T] {
  def updateLazyFromData(l: T, data: T): T

  def updateDataFromLazy(data: T, l: T): T

  def calcLazyWithLen(l: T, len: Int): T
}

trait LazyMonoid[T] extends Monoid[T] with LazyOperation[T]

class SegmentTree[T](val n: Int)(implicit monoid: LazyMonoid[T], classTag: ClassTag[T]) {

  import monoid._

  var sz = 1
  while (sz < n) sz *= 2
  val seg = Array.fill[T](2 * sz - 1)(zero)
  val _lazy = Array.fill[T](2 * sz - 1)(zero)

  def update(i: Int, x: T): Unit = {
    var i2 = i + sz - 1
    seg(i2) = x
    while (i2 > 0) {
      i2 = (i2 - 1) / 2
      seg(i2) = combineFn(seg(2 * i2 + 1), seg(2 * i2 + 2))
    }
  }

  def build(v: Array[T]): Unit = {
    for (i <- 0 until n) seg(i + sz - 1) = v(i)
    for (i <- sz - 2 to 0 by -1) {
      seg(i) = combineFn(seg(2 * i + 1), seg(2 * i + 2))
    }
  }

  def update(a: Int, b: Int, x: T): Unit = update(a, b, x, 0, 0, sz)

  def query(a: Int, b: Int): T = query(a, b, 0, 0, sz)

  private def eval(len: Int, k: Int): Unit = {
    if (_lazy(k) == zero) return
    if (2 * k + 1 < sz * 2 - 1) {
      _lazy(2 * k + 1) = updateLazyFromData(_lazy(2 * k + 1), _lazy(k))
      _lazy(2 * k + 2) = updateLazyFromData(_lazy(2 * k + 2), _lazy(k))
    }
    seg(k) = updateDataFromLazy(seg(k), calcLazyWithLen(_lazy(k), len))
    _lazy(k) = zero
  }

  private def update(a: Int, b: Int, x: T, k: Int, l: Int, r: Int): Unit = {
    eval(r - l, k)
    if (r <= a || b <= l) return
    if (a <= l && r <= b) {
      _lazy(k) = updateLazyFromData(_lazy(k), x)
      eval(r - l, k)
    } else {
      val m = (l + r) / 2
      update(a, b, x, 2 * k + 1, l, m)
      update(a, b, x, 2 * k + 2, m, r)
      seg(k) = combineFn(seg(2 * k + 1), seg(2 * k + 2))
    }
  }

  private def query(a: Int, b: Int, k: Int, l: Int, r: Int): T = {
    if (r <= a || b <= l) return zero
    eval(r - l, k)
    if (a <= l && r <= b) return seg(k)
    val m = (l + r) / 2
    combineFn(query(a, b, 2 * k + 1, l, m), query(a, b, 2 * k + 2, m, r))
  }
}

object SegmentTree {
  def rangeMinimumQuery(n: Int): SegmentTree[Long] = {
    implicit object LongMinMonoid extends LazyMonoid[Long] {
      override val combineFn: (Long, Long) => Long = _ min _

      override def zero: Long = Int.MaxValue

      override def updateLazyFromData(l: Long, data: Long): Long = data

      override def updateDataFromLazy(data: Long, l: Long): Long = l

      override def calcLazyWithLen(l: Long, len: Int): Long = l
    }
    new SegmentTree[Long](n)
  }

  def rangeMaxQuery(n: Int): SegmentTree[Long] = {
    implicit object LongMaxMonoid extends LazyMonoid[Long] {
      override val combineFn: (Long, Long) => Long = _ max _

      override def zero: Long = Long.MinValue

      override def updateLazyFromData(l: Long, data: Long): Long = data

      override def updateDataFromLazy(data: Long, l: Long): Long = l

      override def calcLazyWithLen(l: Long, len: Int): Long = l
    }
    new SegmentTree[Long](n)
  }

  def rangeSumTree(n: Int): SegmentTree[Long] = {
    implicit object LongSumMonoid extends LazyMonoid[Long] {
      override val combineFn: (Long, Long) => Long = _ + _

      override def zero: Long = 0L

      override def updateLazyFromData(l: Long, data: Long): Long = l + data

      override def updateDataFromLazy(data: Long, l: Long): Long = data + l

      override def calcLazyWithLen(l: Long, len: Int): Long = l * len
    }
    new SegmentTree[Long](n)
  }
}

// verified with https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=7460199#2
object SegmentTreeVerify {
  def main(args: Array[String]): Unit = {
    val nq = readLine().split(" ").map(_.toInt)
    val n = nq(0)
    val q = nq(1)
    val tree = SegmentTree.rangeMinimumQuery(n)
    for (_ <- 0 until q) {
      val line = readLine().split(" ")
      val com = line(0).toInt
      val x = line(1).toInt
      val y = line(2).toInt
      com match {
        case 0 =>
          tree.update(x, y)
        case 1 =>
          println(tree.query(x, y + 1))
      }
    }
  }
}