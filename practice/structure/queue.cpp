#include <iostream>
class Queue {
    private:
        static const int MAX_SIZE = 4;
        int queue[MAX_SIZE];
        int front;
        int back;

        int next_idx(int idx) {
            return (idx + 1) % MAX_SIZE;
        }
    public:
        Queue() {
            front = 0;
            back = 0;
        }

        void enqueue(int x) {
            queue[back] = x;
            back = next_idx(back);
        }

        int dequeue() {
            int ret = queue[front];
            front = next_idx(front);
            return ret;
        }

        bool empty() {
            return back == front;
        }
};
using namespace std;

int main() { 
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.dequeue();
    queue.enqueue(4);
    queue.dequeue();
    queue.enqueue(5);
    while (!queue.empty()){
        cout << queue.dequeue() << endl;
    }
    return 0;
}
