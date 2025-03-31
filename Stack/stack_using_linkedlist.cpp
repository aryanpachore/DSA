#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class using a linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr; // Initialize top to null
    }

    // Push operation to add an element to the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top; // Link the new node to the previous top
        top = newNode;       // Update the top to the new node
        cout << value << " pushed onto stack.\n";
    }

    // Pop operation to remove the top element of the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node* temp = top;
        top = top->next; // Update top to the next element
        cout << temp->data << " popped from stack.\n";
        delete temp; // Free the memory of the removed node
    }

    // Peek operation to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek.\n";
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Test the stack implementation
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    stack.pop();
    stack.pop(); // Trying to pop from an empty stack

    return 0;
}
    