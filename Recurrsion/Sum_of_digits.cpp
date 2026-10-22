#include <iostream>
using namespace std;

int sum_of_digit(int n){
    if(n == 0){
        return 0;
    }

    return (n % 10) + sum_of_digit(n/10);
}

int main(){
    while (true) {
        string input;

        cout << "Enter a number (E to exit): ";
        cin >> input;

        if (input == "E" || input == "e") {
            break;
        }

        try {
            int n = stoi(input);

            if (n < 0) {
                n = -n;
            }

            cout << "Sum of the digits: " << sum_of_digit(n) << endl;
        }
        catch (...) {
            cout << "Please enter a valid integer." << endl;
        }
    }




    return 0;
}