//STARTING WITH THE BASICS OF RECURSION(A function calling itself)
#include <iostream>
using namespace std;

//Example 1: Print Number 1 to N
void printascending(int n){
    if(n == 0){
        return;
    }

    printascending(n-1);
    cout << n << " ";
}

//Example 2: Print Number N to 1
void printdescending(int n){
    if(n == 0){
        return;
    }

    cout << n << " ";
    printdescending(n-1);


}

int main(){
    while(1){
        int n, c;
        cout << "Enter the Number: ";
        cin >> n;

        cout << "Print(1 or 2): \n1.Ascending \n2.Descending" << endl;
        cin >> c;

        switch(c){
            case 1:
                printascending(n);
                cout << endl;
                break;
                case 2:
                printdescending(n);
                cout << endl;
                break;
            default:
                cout << "Enter 1 or 2" << endl;
        }
    }


    return 0;
}