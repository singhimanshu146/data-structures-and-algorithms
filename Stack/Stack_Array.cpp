#include <iostream>
using namespace std;

#define MAX 100

int Stack[MAX], top = -1;

//PUSH
void push(){
    int el;
    cout << "Enter the Element: ";
    cin >> el;
    
    if(top == MAX - 1){
        cout << "The Stack is Full\n" << endl;
        return;
    
    }
    else{
        Stack[++top] = el;
        cout << "Element Inserted Successfully!\n" << endl;
        return;
    }
}


//POP
void pop(){
    if(top == -1){
        cout << "Already Empty\n" << endl;
        return;
    }
    else{
        cout << "Popped" << Stack[top] << "from Stack\n" << endl;
        top--;
        return;
    }
}
//PEAK
void peek(){
    if(top == -1){
        cout << "Nothing in the Stack!\n" << endl;
        return;
    }
    else{
        cout << "Top Element " << Stack[top] << "\n" << endl;
        return;
    }
}

//DISPLAY
void Display(){
    if (top == -1) {
        cout << "Stack is empty\n" << endl;
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << Stack[i] << " ";
    }
    cout << "\n" << endl;
    return;
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