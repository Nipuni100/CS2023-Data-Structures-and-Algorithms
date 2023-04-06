#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>

using namespace std;
using namespace std::chrono;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* t = new Node;
        if (t == nullptr) {
            std::cout << "Stack Overflow" << std::endl;
        } else {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        } else {
            int x = top->data;
            Node* t = top;
            top = top->next;
            delete t;
            return x;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        Node* t = new Node;
        bool full = (t == nullptr);
        delete t;
        return full;
    }

    int stackTop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        } else {
            return top->data;
        }
    }

    void display() {
        Node* p = top;
        std::cout << "Stack: ";
        while (p != nullptr) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    auto start1 = high_resolution_clock::now();

    //Do something
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    for(int i=0;i<5;i++){
        s.pop();
    }
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout<<endl;

    cout << "Time taken by the implementation of Stack using LinkedList: "
         << duration.count() << " microseconds" << endl;

    
    
    return 0;
}
