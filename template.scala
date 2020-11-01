import scala.io.StdIn._

object Main {
  import Util._
  def solve(): Unit = {
  }
  def main(args: Array[String]): Unit = solve()
}

object Util {
  def rep(n: Int)(f: Int => Unit): Unit = for (i <- 0 until n) f(i)
  def repYield[T](n: Int)(f: Int => T): IndexedSeq[T] = for (i <- 0 until n) yield f(i)

  implicit class Extend[T](value: T) {
    def also(func: T => Unit): T = {
      func(value)
      value
    }

    def let[A](func: T => A): A = func(value)
  }

}
