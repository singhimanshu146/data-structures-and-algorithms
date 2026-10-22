#include <iostream>
#include <string>
using namespace std;

int reverse_number(int n, int rev = 0) {
    if (n == 0) {
        return rev;
    }

    return reverse_number(n / 10, rev * 10 + n % 10);
}

int main() {
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
                cout << "Reversed number: -" << reverse_number(-n) << endl;
            } else {
                cout << "Reversed number: " << reverse_number(n) << endl;
            }
        }
        catch (...) {
            cout << "Please enter a valid integer." << endl;
        }
    }

    return 0;
}