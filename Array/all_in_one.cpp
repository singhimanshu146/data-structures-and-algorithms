#include<iostream>
using namespace std;
#define MAX 100

int Arr[MAX], size =0;

//INSERION FUNCTION

void InsertAtBeg(){                                                            //INSERT AT BEGINGING
    cout << "Enter the number to insert: ";
    int a;
    cin >> a;
    if(size >= 100){
        cout << "The Array is full\n" << endl;
        return;
    }
    for(int i = size-1; i >= 0; i--){
        Arr[i+1] = Arr[i];
    }
    Arr[0] = a;
    size++;
    cout << "ELEMENT SUCCESSFULLY INSERTED\n\n";
}


void InsertAtPos(){                                                            //INSERT AT POSITION
    cout << "Enter the position: ";
    int pos, el;
    cin >> pos;

    if(size >= MAX || pos < 1 || pos > size + 1){
        cout << "Invalid Postion";
        return;
    }
    cout << "Enter the element: ";
    cin >> el;
    for(int i = size-1; i >= pos-1; i--){
        Arr[i+1] = Arr[i];
    }
    Arr[pos-1] = el;
    size++;
    cout << "SUCCESSFULLY INSERTED AT POSITION " << pos << "\n" << endl;
}


void InsertAtEnd(){                                                            //INSERT AT END
    cout << "Enter the Element: ";
    if(size >= 100){
        cout << "The Array is full\n" << endl;
        return;
    }
    int el;
    cin >> el;
    Arr[size] = el;
    size++;
}

//UPDATEION OF ELEMENTS
void UpdateArr(){
    cout << "Enter the position to be modified: ";
    int i, el;
    cin >> i;
    if(i < 1 || i > size){
        cout << "Invalid Positon\n" << endl;
        return;
    }
    cout << "Enter the New Value: ";
    cin >> el;
    Arr[i-1] = el;
}

//DELTION OF ELEMENT

void DeleteFromBeg(){                                                          //DELETE FROM BEGINING
    if(size == 0){
        cout << "Nothing to delete\n" << endl;
        return;
    }

    for(int i = 0; i < size-1; i++){
        Arr[i] = Arr[i+1];
    }
    size--;
}


void DeleteAtPos(){                                                            //DELETE FROM POSITION
    if(size == 0){
        cout << "The Array is Already empty.\n" << endl;
        return;
    }
    
    cout << "Enter the possition to delete: ";
    int pos;
    cin >> pos;

    if(pos < 1 || pos > size){
        cout << "The position is already empty.\n" << endl;
        return;
    }
    
    for(int i = pos-1; i < size-1; i++){
        Arr[i] = Arr[i+1];
    }
    size--;
}


void DeleteFromEnd(){                                                           //DLEETE END ELEMENT
    if(size == 0){
        cout << "The Array is already Empty\n" << endl;
        return;
    }
    size--;
}

//SEARCH THE ELEMENT
void Search(){
    if(size == 0){
        cout << "Array is Empty\n" << endl;
        return;
    }
    cout << "Enter the element to search: ";
    int el;
    cin >> el;
    for(int i = 0; i < size; i++){
        if(Arr[i] == el){
            cout << "Found at position: " << i + 1 << "\n" << endl;
            return;
        }
    }
    cout << "Element not FOUND!";
}

//DISPLAY THE ELEMENTS
void Display(){
    if(size == 0){
        cout << "Nothing to Display(Array is empty)";
        return;
    }
    cout << "ELEMENTS OF THE ARRAY: ";
    for(int i = 0; i < size; i++){
        cout << Arr[i];
        cout << " ";
    }
    cout << "\n" << endl;
}


int main(){
    while(1){
        // SELECT THE OPERATIONS TO PERFORM
        cout << "1.Insert\n2.Update\n3.Delete\n4.Search a element\n5.Display\n6.EXIT the program.\nEnter the choice(1-6): ";
        int n;
        cin >> n;
        switch(n){

            //CASE: 1 
            case 1:
                int ch1;
                cout << "\n1. Insert at begining\n2. Insert at position\n3. Insert at End\nEnter the choice: ";
                cin >> ch1;
                switch(ch1){
                    case 1:
                        InsertAtBeg();
                        break;
                    case 2:
                        InsertAtPos();
                        break;
                    case 3:
                        InsertAtEnd();
                        break;
                    default:
                        cout << "Enter a Valid Choices\n";
                }
                break;

            //CASE: 2
            case 2:
                UpdateArr();
                break;

            //CASE: 3
            case 3:
                int ch3;
                cout << "1. Delete from begining\n2. Delete from a position\n3. Delete At End\nEnter the choice: ";
                cin >> ch3;
                switch(ch3){
                    case 1:
                        DeleteFromBeg();
                        break;
                    case 2:
                        DeleteAtPos(); 
                        break;
                    case 3:
                        DeleteFromEnd();
                        break;
                    default:
                        cout << "Enter a Valid Choices";
                }
                break;
            //CASE: 4
            case 4:
                Search();
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