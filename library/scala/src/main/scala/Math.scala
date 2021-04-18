import scala.annotation.tailrec

object Math {
  @tailrec
  def gcd(m: Int, n: Int): Int = {
    if (n == 0) m
    else gcd(n, m % n)
  }

  def lcm(m: Int, n: Int): Int = {
    if (m == 0 || n == 0) 0
    else (m / gcd(m, n)) * n
  }
}
