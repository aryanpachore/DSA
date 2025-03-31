#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    Node* qfront;
    Node* rear;

public:
    Queue() {
        qfront = nullptr;
        rear = nullptr;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return qfront == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            // If queue is empty
            qfront = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (qfront == nullptr) {
            // Queue is empty
            return -1;
        }
        int ans = qfront->data;
        Node* temp = qfront;
        qfront = qfront->next;

        // If the queue becomes empty
        if (qfront == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return ans;
    }

    int front() {
        if (qfront == nullptr) {
            // Queue is empty
            return -1;
        }
        return qfront->data;
    }
};

int main() {
    Queue s;

    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);

    cout << "Front element is: " << s.front() << endl;

    s.dequeue();
    cout << "Front element is: " << s.front() << endl;

    if (s.isEmpty()) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue is not Empty" << endl;
    }

    return 0;
}
    