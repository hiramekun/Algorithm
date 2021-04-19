import scala.annotation.tailrec

object Math {

  trait Mod[A] {
    def mod(p: A): A

    def isZero: Boolean

    def multi(p: A): A

    def zero: A

    def div(p: A): A
  }

  implicit class IntMod(r: Int) extends Mod[Int] {
    override def mod(p: Int): Int = r % p

    override def isZero: Boolean = r == 0

    override def multi(p: Int): Int = r * p

    override def zero: Int = 0

    override def div(p: Int): Int = r / p
  }

  implicit class LongMod(r: Long) extends Mod[Long] {
    override def mod(p: Long): Long = r % p

    override def isZero: Boolean = r == 0.toLong

    override def multi(p: Long): Long = r * p

    override def zero: Long = 0.toLong

    override def div(p: Long): Long = r / p
  }

  @tailrec
  def gcd[T](m: T, n: T)(implicit env: T => Mod[T]): T = {
    if (n.isZero) m
    else gcd(n, m mod n)
  }

  def lcm[T](m: T, n: T)(implicit env: T => Mod[T]): T = {
    if (m.isZero || n.isZero) n.zero
    else (m div gcd(m, n)) multi n
  }
}

import Math._

import scala.io.Source._

// verified with https://onlinejudge.u-aizu.ac.jp/status/users/hiramekun/submissions/1/0005/judge/5390914/Scala
object MathVerify {
  def main(args: Array[String]): Unit = {
    for (l <- stdin.getLines()) {
      val ab = l.split(" ").map(_.toInt)
      val a = ab(0)
      val b = ab(1)
      println(s"${gcd(a, b)} ${lcm(a, b)}")
    }
  }
}
