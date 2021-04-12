import scala.annotation.tailrec
import scala.io.StdIn._

case class BinarySearch[T](arr: Vector[T])(implicit ord: Ordering[T]) {

  import ord._

  def find(key: T): Int = {
    @tailrec
    def rec(l: Int, r: Int, key: T): Int = {
      val mid = (r + l) / 2
      if (r < l) -1
      else if (arr(mid) == key) mid
      else if (arr(mid) > key) rec(l, mid - 1, key)
      else rec(mid + 1, r, key)
    }

    val left = 0
    val right = arr.size - 1
    rec(left, right, key)
  }
}

// verified with: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5358306#1
object BinarySearch {
  def solve(): Unit = {
    val _ = readInt()
    val s = readLine.split(" ").map(_.toInt)
    val _ = readInt()
    val t = readLine.split(" ").map(_.toInt)
    val sortedT = t.sorted
    val binarySearch = BinarySearch(sortedT.toVector)
    println(s.distinct.count(binarySearch.find(_) > -1))
  }

  def main(args: Array[String]): Unit = solve()
}
