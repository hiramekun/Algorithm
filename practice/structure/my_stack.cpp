#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


class MyStack {
    private:
        const int DEFALT_STACK_SIZE = 100;
        int stack[DEFALT_STACK_SIZE];
        int stack_size;
        int sp;
    public:
        MyStack() {
            MyStack(DEFALT_STACK_SIZE);
        }

        MyStack(int size) {
            stack_size = size;
            stack = new int[stack_size];
            sp = 0;
        }

        void clear() {
            fill(stack, stack + stack_size, 0);
            sp = 0;
        }

        void push(int x) {
            if (sp >= stack_size) {
                throw "Illegal state: stack overflow";
            }
            stack[sp++] = x;
        }

        int pop() {
            if (sp <= 0) {
                throw "Empty stack";
            }
            int ret = stack[--sp];
            stack[sp] = 0;
            return ret;
        }

        bool is_empty() {
            return sp == 0;
        }

        ~MyStack() {
           if (stack != NULL) {
               delete [] stack;
           }
        }
};

