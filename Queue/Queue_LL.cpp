#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

node *front = nullptr;
node *rear = nullptr;

// ENQUEUE OPERATION
void enqueue() {
    cout << "Enter the element: ";
    int el;
    cin >> el;

    node *newnode = new node();

    newnode->data = el;
    newnode->next = nullptr;

    if (front == nullptr) {
        front = rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }

    cout << el << " Inserted Successfully in the Queue!\n" << endl;
}

// DEQUEUE OPERATION
void dequeue() {
    if (front == nullptr) {
        cout << "Queue underflow\n" << endl;
        return;
    }

    node *temp = front;
    cout << front->data << " Deleted from Queue\n" << endl;

    front = front->next;

    // If the queue becomes empty
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
}

// PEEK OPERATION
void peek() {
    if (front == nullptr) {
        cout << "Queue is Empty!\n" << endl;
        return;
    }

    cout << "FRONT element: " << front->data << "\n" << endl;
}

// DISPLAY OPERATION
void Display() {
    if (front == nullptr) {
        cout << "The Queue is Empty\n" << endl;
        return;
    }

    node *temp = front;

    cout << "The Queue is:\n";

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n" << endl;
}

int main() {
    while (1) {
        // SELECT THE OPERATIONS TO PERFORM
        cout << "THIS IS THE QUEUE!\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n3.Peek\n5.EXIT\nEnter the choice(1-5): ";

        int n;
        cin >> n;

        switch (n) {
            // CASE: 1
            case 1:
                enqueue();
                break;

            // CASE: 2
            case 2:
                dequeue();
                break;

            // CASE: 3
            case 3:
                peek();
                break;

            // CASE: 4
            case 4:
                Display();
                break;

            // CASE: 5
            case 5:
                return 0;

            default:
                cout << "Enter a Valid Choice\n" << endl;
        }
    }

    return 0;
}