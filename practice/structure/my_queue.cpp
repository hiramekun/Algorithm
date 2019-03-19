#include <cstdio>
#include <iostream>

class MyQueue {
private:
    const int DEFAULT_QUEUE_SIZE = 100;
    int queue[DEFAULT_QUEUE_SIZE];
    int queue_size;
    int front;
    int rear;
public:
    MyQueue(int size) {
        queue_size = size;
        queue = new int[queue_size];
        front = rear = 0;
    }

MyQueue: MyQueue(DEFAULT_QUEUE_SIZE) {}
private:
    int next(int a) {
        return (a + 1) % queue_size;
    }

public:
    void clear() {
        front = rear = 0;
        fill(queue, queue + queue_size, 0);
    }

    void enqueue(int x) {
        if (next(rear) == front) {
            throw "Illeagal State";
        }
        queue[rear] = x;
        rear = next(rear);
    }

    void dequeue() {
        if (front == rear) {
            throw "No Such Element";
        }
        int x = queue[front];
        queue[front] = 0;
        front = next(front);
        return x;
    }

    bool is_empty() {
        return front == rear;
    }
};

