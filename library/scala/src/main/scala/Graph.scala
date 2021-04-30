import java.util.Scanner
import scala.collection.mutable

case class Edge(to: Int, w: Long)

case class Graph(n: Int) {
  val g: Array[Array[Edge]] = Array.fill(n)(Array.empty)

  def push(from: Int, edge: Edge): Unit = {
    g(from) :+= edge
  }

  def dijkstra(start: Int, Inf: Long = 1e18.toLong): Array[Long] = {
    val d = Array.fill(n)(Inf)
    d(start) = 0
    val queue = mutable.PriorityQueue.empty[(Long, Int)](Ordering.Tuple2[Long, Int].reverse)
    queue.enqueue((0, start))

    while (queue.nonEmpty) {
      val (minCost, minV) = queue.dequeue()
      if (d(minV) >= minCost) {
        g(minV).foreach { e =>
          if (d(e.to) > d(minV) + e.w) {
            d(e.to) = d(minV) + e.w
            queue.enqueue((d(e.to), e.to))
          }
        }
      }
    }
    d
  }
}

// verified with https://onlinejudge.u-aizu.ac.jp/status/users/hiramekun/submissions/1/GRL_1_A/judge/5437229/Scala
object GraphVerify {
  def main(args: Array[String]): Unit = {
    val Inf = 1e18.toLong
    val sc = new Scanner(System.in)
    val v, e, r = sc.nextInt()
    val g = Graph(v)
    for (_ <- 0 until e) {
      val s, t, d = sc.nextInt()
      g.push(s, Edge(t, d))
    }
    val res = g.dijkstra(r, Inf)
    res.foreach(d => if (d == Inf) println("INF") else println(d))
  }
}