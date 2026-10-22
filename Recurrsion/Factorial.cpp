#include <iostream>
using namespace std;


int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    while(1){
        int n;
        cout << "Eneter a Numebr: ";
        cin >> n;
        if(n < 0){
            cout << "Enter a Positive number"<< endl;
        }
        else{
            int fac = factorial(n);
            cout << "factorial: " << fac << endl;

        }
    }

    return 0;
}