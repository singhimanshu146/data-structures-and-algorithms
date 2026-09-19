#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

node *head = nullptr;

//INSERT
//INSSERT AT BEGINNING
void InsertAtBeg() {

    int value;

    cout << "Enter the value: ";
    cin >> value;

    node *newNode = new node;

    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    // If list is not empty
    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;

    cout << "Node inserted at beginning.\n" << endl;
}

//INSERT AT POSITION
void InsertAtPos() {

    int value, pos;

    cout << "Enter the position: ";
    cin >> pos;

    cout << "Enter the value: ";
    cin >> value;

    // Invalid position
    if (pos <= 0) {
        cout << "Invalid position.\n" << endl;
        return;
    }

    // Insert at beginning
    if (pos == 1) {
        InsertAtBeg();
        return;
    }

    node *temp = head;

    // Move to the node before the required position
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Position does not exist
    if (temp == nullptr) {
        cout << "Invalid position.\n" << endl;
        return;
    }

    node *newNode = new node;

    newNode->data = value;

    // Connect new node
    newNode->prev = temp;
    newNode->next = temp->next;

    // If there is a next node
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    cout << "Node inserted at position " << pos << ".\n" << endl;
}

//INSERT AT END
void InsertAtEnd() {

    int value;

    cout << "Enter the value: ";
    cin >> value;

    node *newNode = new node;

    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {

        newNode->prev = nullptr;
        head = newNode;

        cout << "Node inserted at end.\n" << endl;
        return;
    }

    node *temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;

    cout << "Node inserted at end.\n" << endl;
}

//UPDATE
void Update() {

    int pos, value;

    cout << "Enter the position: ";
    cin >> pos;

    cout << "Enter the new value: ";
    cin >> value;

    if (pos <= 0 || head == nullptr) {
        cout << "Invalid position.\n" << endl;
        return;
    }

    node *temp = head;

    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position.\n" <<endl;
        return;
    }

    temp->data = value;

    cout << "Node updated successfully.\n" << endl;
}


//DELETE
//DELETE FROM BEGNING
void DeleteFromBeg() {

    if (head == nullptr) {
        cout << "List is empty.\n" << endl;
        return;
    }

    node *temp = head;

    head = head->next;

    // If list still has nodes
    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;

    cout << "Node deleted from beginning.\n" << endl;
}


//DLEETE FORM POSITION
void DeleteAtPos() {

    int pos;

    cout << "Enter the position: ";
    cin >> pos;

    if (head == nullptr) {
        cout << "List is empty.\n" << endl;
        return;
    }

    if (pos <= 0) {
        cout << "Invalid position.\n" << endl;
        return;
    }

    if (pos == 1) {
        DeleteFromBeg();
        return;
    }

    node *temp = head;

    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position.\n" << endl;
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << "Node deleted from position " << pos << ".\n" <<endl;
}


//DLEETE FORM END 
void DeleteFromEnd() {

    if (head == nullptr) {
        cout << "List is empty.\n" << endl;
        return;
    }

    if (head->next == nullptr) {

        delete head;
        head = nullptr;

        cout << "Node deleted from end.\n" <<endl;
        return;
    }

    node *temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;

    delete temp;

    cout << "Node deleted from end.\n" << endl;
}


//SEARCH
void Search() {

    int value;

    cout << "Enter the value to search: ";
    cin >> value;

    node *temp = head;

    int position = 1;

    while (temp != nullptr) {

        if (temp->data == value) {

            cout << "Value found at position " << position << ".\n" << endl;

            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Value not found.\n" << endl;
}



//DISPLAY
void Display() {

    if (head == nullptr) {
        cout << "List is empty.\n" << endl;
        return;
    }

    node *temp = head;

    cout << "Doubly Linked List: ";

    while (temp != nullptr) {

        cout << temp->data;

        if (temp->next != nullptr) {
            cout << " <-> ";
        }

        temp = temp->next;
    }

    cout << " -> NULL\n" << endl;
}



int main(){
    while(1){
        // SELECT THE OPERATIONS TO PERFORM
        cout << "1.Insert\n2.Update\n3.Delete\n4.Search\n5.Display\n6.EXIT the program.\nEnter the choice(1-6): ";
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
                Update();
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