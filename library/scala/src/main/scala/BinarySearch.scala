import Implicits._

import scala.annotation.tailrec
import scala.io.StdIn._


object Implicits {
  implicit def binarySearchWrap[T](arr: Vector[T])(implicit ord: Ordering[T]): BinarySearch[T] = BinarySearch(arr)
}

case class BinarySearch[T](arr: Vector[T])(implicit ord: Ordering[T]) {

  import ord._

  /**
    * @return
    * the index of key element.
    * if does not exists, return None.
    */
  def find(key: T): Option[Int] = {
    @tailrec
    def rec(l: Int, r: Int, key: T): Option[Int] = {
      val mid = (r + l) / 2
      if (r < l) None
      else if (arr(mid) == key) Some(mid)
      else if (arr(mid) > key) rec(l, mid - 1, key)
      else rec(mid + 1, r, key)
    }

    val left = 0
    val right = arr.size - 1
    rec(left, right, key)
  }

  /**
    * @return
    * the minimum index which satisfies condition `arr(idx) > key`.
    * if any index does not satisfies the condition, return None.
    */
  def upperBound(key: T): Option[Int] = recByIndex(_ > key)

  /**
    * @return
    * the minimum index which satisfies condition `arr(idx) >= key`.
    * if any index does not satisfies the condition, return None.
    */
  def lowerBound(key: T): Option[Int] = recByIndex(_ >= key)

  private def recByIndex(condition: T => Boolean): Option[Int] = {
    @tailrec
    def rec(l: Int, r: Int): Option[Int] = {
      val mid = (r + l) / 2
      if (r <= l + 1) {
        if (r == arr.size) None
        else Some(r)
      }
      else if (condition(arr(mid))) rec(l, mid)
      else rec(mid, r)
    }

    rec(-1, arr.size)
  }
}

// verified with: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5369610#2
object BinarySearchFind {
  def solve(): Unit = {
    val n = readInt()
    val s = readLine.split(" ").map(_.toInt)
    val q = readInt()
    val t = readLine.split(" ").map(_.toInt)
    val sortedT = t.sorted.toVector
    println(s.distinct.count(sortedT.find(_).isDefined))
  }

  def main(args: Array[String]): Unit = solve()
}


// verified with: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5369499#2
object BinarySearchLowerBound {
  def solve(): Unit = {
    val n = readInt()
    val s = readLine.split(" ").map(_.toInt)
    val q = readInt()
    val t = readLine.split(" ").map(_.toInt)
    val sortedT = t.sorted.toVector
    println(s.distinct.count { num =>
      sortedT.lowerBound(num) match {
        case Some(i) => sortedT(i) == num
        case None => false
      }
    })
  }

  def main(args: Array[String]): Unit = solve()
}
