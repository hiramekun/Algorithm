import scala.annotation.tailrec

case class BinarySearch[T](arr: Vector[T])(implicit ord: Ordering[T]) {

  import ord._

  def find(key: T): Int = {
    @tailrec
    def rec(l: Int, r: Int, key: T): Int = {
      val mid = l + (r - l) / 2
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

object BinarySearch extends App {
  final val n = 8
  final val arr = Vector(3, 5, 8, 10, 14, 7, 21, 39)
  val binarySearch = BinarySearch(arr)
  assert(binarySearch.find(10) == 3)
  assert(binarySearch.find(3) == 0)
  assert(binarySearch.find(-100) == -1)
  assert(binarySearch.find(9) == -1)
  assert(binarySearch.find(100) == -1)
  println("Success!!")
}