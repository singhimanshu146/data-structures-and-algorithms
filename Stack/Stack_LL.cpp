#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

 node *top = nullptr;

//PUSH OPERATION
void push(){
    cout << "Enter the element: ";
    int el;
    cin >> el;
    node * newnode = new node();

    newnode->data= el;
    newnode->next = top;
    top = newnode;

    cout << el << " Pushed Successfully in the Stack!\n" << endl;

}

//POP OPERATION
void pop(){
    if(top == nullptr){
        cout << "Stack underflow\n" << endl;
        return;;
    }

    node *temp = top;
    cout << top->data << " Popped from Stack\n" << endl;

    top = top->next;
    delete temp;
}

//PEEK OPERATION
void peek(){
    if(top == nullptr){
        cout << "Stack is Empty!\n" << endl;
        return;
    }

    cout << "TOP element: " << top->data << "\n" << endl;

}

//DISPLAY OPERATION
void Display(){
    if(top == nullptr){
        cout << "The Stack is Empty\n" << endl;
        return;
    }

    node *temp = top;
    cout << "The Stack is:\n";
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n" << endl;

}


int main(){
    while(1){
        // SELECT THE OPERATIONS TO PERFORM
        cout << "THIS IS THE STACK!\n1.Push \n2.Pop \n3.Peek \n4.Display \n5.EXIT\nEnter the choice(1-5): ";
        int n;
        cin >> n;
        switch(n){
            //CASE: 1
            case 1:
                push();
                break;
            //CASE: 2

            case 2:
                pop();
                break;

            //CASE: 3
            case 3:
                peek();
                break;
            //CASE: 4
            case 4:
                Display(); 
                break;
            //CASE: 5
            case 5:
                return 0;

            default:
                cout << "Enter a Valid Choices\n" << endl;
        }
    }

    return 0;
}