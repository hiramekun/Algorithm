import scala.io.StdIn.readLine

object SegmentTree {
  type Data = Long
  type Lazy = Long
  type MergeData = (Data, Data) => Data
  type UpdateLazyFromX = (Lazy, Lazy) => Lazy
  type UpdateDataFromLazy = (Data, Lazy) => Data
  type CalcLazyWithLen = (Lazy, Int) => Lazy
}

import SegmentTree._

class SegmentTree
(val n: Int,
 val fm: MergeData,
 val fl: UpdateLazyFromX,
 val fa: UpdateDataFromLazy,
 val fw: CalcLazyWithLen,
 val M1: Data,
 val A1: Lazy) {
  var sz = 1
  while (sz < n) sz *= 2
  val seg = Array.fill[Data](2 * sz - 1)(M1)
  val _lazy = Array.fill[Lazy](2 * sz - 1)(A1)

  def update(i: Int, x: Data): Unit = {
    var i2 = i + sz - 1
    seg(i2) = x
    while (i2 > 0) {
      i2 = (i2 - 1) / 2
      seg(i2) = fm(seg(2 * i2 + 1), seg(2 * i2 + 2))
    }
  }

  def build(v: Array[Data]): Unit = {
    for (i <- 0 until n) seg(i + sz - 1) = v(i)
    for (i <- sz - 2 to 0 by -1) {
      seg(i) = fm(seg(2 * i + 1), seg(2 * i + 2))
    }
  }

  def update(a: Int, b: Int, x: Data): Unit = update(a, b, x, 0, 0, sz)

  def query(a: Int, b: Int): Data = query(a, b, 0, 0, sz)

  private def eval(len: Int, k: Int): Unit = {
    if (_lazy(k) == A1) return
    if (2 * k + 1 < sz * 2 - 1) {
      _lazy(2 * k + 1) = fl(_lazy(2 * k + 1), _lazy(k))
      _lazy(2 * k + 2) = fl(_lazy(2 * k + 2), _lazy(k))
    }
    seg(k) = fa(seg(k), fw(_lazy(k), len))
    _lazy(k) = A1
  }

  private def update(a: Int, b: Int, x: Data, k: Int, l: Int, r: Int): Unit = {
    eval(r - l, k)
    if (r <= a || b <= l) return
    if (a <= l && r <= b) {
      _lazy(k) = fl(_lazy(k), x)
      eval(r - l, k)
    } else {
      val m = (l + r) / 2
      update(a, b, x, 2 * k + 1, l, m)
      update(a, b, x, 2 * k + 2, m, r)
      seg(k) = fm(seg(2 * k + 1), seg(2 * k + 2))
    }
  }

  private def query(a: Int, b: Int, k: Int, l: Int, r: Int): Data = {
    if (r <= a || b <= l) return M1
    eval(r - l, k)
    if (a <= l && r <= b) return seg(k)
    val m = (l + r) / 2
    fm(query(a, b, 2 * k + 1, l, m), query(a, b, 2 * k + 2, m, r))
  }
}

object RangeMinimumTree {
  def apply(n: Int): SegmentTree = {
    val fm = (a: Long, b: Long) => a min b
    val fl = (_: Long, b: Long) => b
    val fa = (_: Long, b: Long) => b
    val fw = (a: Long, _: Int) => a

    new SegmentTree(n, fm, fl, fa, fw, Int.MaxValue, Int.MaxValue)
  }
}

// verified with https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=7456366#2
object SegmentTreeVerify {
  def main(args: Array[String]): Unit = {
    val nq = readLine().split(" ").map(_.toInt)
    val n = nq(0)
    val q = nq(1)
    val tree = RangeMinimumTree(n)
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