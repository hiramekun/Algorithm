import scala.annotation.tailrec

object Gcd {
  @tailrec
  def gcd(m: Int, n: Int): Int = {
    if (n == 0) m
    else gcd(n, m % n)
  }
}
