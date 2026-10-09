#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// ENQUEUE OPERATION
void enqueue() {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue Overflow!\n" << endl;
        return;
    }

    cout << "Enter the element: ";
    int el;
    cin >> el;

    if (front == -1) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = el;

    cout << el << " Inserted Successfully in the Queue!\n" << endl;
}

// DEQUEUE OPERATION
void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow!\n" << endl;
        return;
    }

    cout << queue[front] << " Deleted from Queue\n" << endl;

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }
}

// PEEK OPERATION
void peek() {
    if (front == -1) {
        cout << "Queue is Empty!\n" << endl;
        return;
    }

    cout << "FRONT element: " << queue[front] << "\n" << endl;
}

// DISPLAY OPERATION
void Display() {
    if (front == -1) {
        cout << "The Queue is Empty\n" << endl;
        return;
    }

    cout << "The Circular Queue is:\n";

    int i = front;

    while (true) {
        cout << queue[i] << " ";

        if (i == rear) {
            break;
        }

        i = (i + 1) % SIZE;
    }

    cout << "\n" << endl;
}

int main() {
    while (1) {
        // SELECT THE OPERATIONS TO PERFORM
        cout << "THIS IS THE CIRCULAR QUEUE!\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.EXIT\nEnter the choice(1-5): ";

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