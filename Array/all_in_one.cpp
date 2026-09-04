#include<iostream>
using namespace std;
#define MAX 100

int Arr[MAX], size =0;

//INSERION FUNCTION

void InsertAtBeg(){                                                            //INSERT AT BEGINGING
    cout << "Enter the number to insert: ";
    int a;
    cin >> a;
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
    if(pos <= 0 || pos > size+1){
        cout << "Invalid Postion";
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
    cout << "Enter the New Value: ";
    cin >> el;
    Arr[i-1] = el;
}

//DELTION OF ELEMENT

void DeleteFromBeg(){                                                          //DELETE FROM BEGINING
    for(int i = 0; i < size-1; i++){
        Arr[i] = Arr[i+1];
    }
    size--;
}


void DeleteAtPos(){                                                            //DELETE FROM POSITION
    cout << "Enter the possition to delete: ";
    int pos;
    cin >> pos;
    for(int i = pos-1; i < size; i++){
        Arr[i] = Arr[i+1];
    }
    size--;
}


void DeleteFromEnd(){                                                           //DLEETE END ELEMENT
    size--;
}


//DISPLAY THE ELEMENTS
void Display(){
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
        cout << "1.Insert\n2.Update\n3.Delete\n4.Search a element\n5.Display\nEnter the choice(1-5): ";
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
                cout << "Call the search function";
                break;
            //CASE: 5
            case 5:
                Display();
                break;
            default:
                cout << "Enter a Valid Choices";
        }
    }
    return 0;
}