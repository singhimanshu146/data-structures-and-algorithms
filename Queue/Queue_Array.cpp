#include <iostream>
using namespace std;
#define MAX 100

int front = -1, rear = -1;
int QUEUE[MAX];

void Enqueue(){                                                             //ENQUEUE
    cout << "Enter the element: ";
    int el;
    cin >> el;

    if(rear == MAX -1){
        cout << "The  Queue is Full!\n" << endl;
        return;
    }
    if(front == -1){
        front = 0;
    }

    rear++;
    QUEUE[rear] = el;

    cout << "Element Inserted Succesfully!\n" << endl;

}


void Dequeue(){                                                             //DEQUEUE
    if(front == -1 || front > rear){
        cout << "The Queue is Empty!\n" << endl;
        return;
    }
    cout << QUEUE[front] << " deleted from Queue!\n" << endl;

    front++;
    if(front > rear){
        front = -1;
        rear = -1;
    }

}

void peek(){                                                                //FRONT
    if(front == -1){
        cout << "Queue is Empty!\n" << endl;
        return;
    }
    cout << "The front element is " << QUEUE[front] << "\n" << endl;

}


void Rear(){                                                                //REAR
    if(rear == -1){
        cout << "Queue is Emplty!\n" << endl;
        return;
    }

    cout << "The rear element is " << QUEUE[rear] << "\n" << endl;
}


void Display(){                                                             //DISPLAY
    if(front == -1){
        cout << "The Queue is Empty!\n" << endl;
        return;
    }

    cout << "The Elements of the Queue are:\n";

    for(int i = front; i <= rear; i++){
        cout << QUEUE[i] << " ";
    }
    cout << "\n" << endl;
}


int main(){
    while(1){
        // SELECT THE OPERATIONS TO PERFORM
        cout << "THIS IS THE QUEUE!\n1.Enqueue \n2.Dequeue \n3.Peek/Front \n4.Rear \n5.Display \n6.EXIT\nEnter the choice(1-6): ";
        int n;
        cin >> n;
        switch(n){
            //CASE: 1
            case 1:
                Enqueue();
                break;
            //CASE: 2

            case 2:
                Dequeue();
                break;

            //CASE: 3
            case 3:
                peek();
                break;

            //CASE: 4
            case 4:
                Rear(); 
                break;

            //CASE: 5
            case 5:
                Display();
                break;

            //CASE: 6
            case 6:
                return 0;

            default:
                cout << "Enter a Valid Choices\n" << endl;
        }
    }

    return 0;
}