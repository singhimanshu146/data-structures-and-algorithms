#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *head = nullptr;

//CREATE
struct node* Createnode(int data){
    struct node *newnode = new node;

    if(newnode == nullptr){
        cout << "Memory Allocation failed\n" << endl;
        exit(1);
    }

    newnode->data = data;
    newnode->next = nullptr;
    return newnode;

}

int input(){                                                                                 //TAKE INPUT DATA
    cout << "Enter the Data: ";
    int n;
    cin >> n;
    return n;
}
//INSERT
void InsertAtBeg(){                                                                          //INSERT AT BEGINING
    int data = input();
    struct node *newnode = Createnode(data);
    
    newnode->next = head;
    head = newnode;

    cout << "Inserted Successfully!\n" << endl;
}                                                                                  

void InsertAtPos(){                                                                          //INSERT AT POSITION
    cout << "Enter the position: ";
    int pos;
    cin >> pos;
    if(pos < 1){
        cout << "Invalid Position\n" << endl;
        return;
    }
    if(pos == 1){
        InsertAtBeg();
        return;
    }

    int data = input();

    struct node *newnode = Createnode(data);

    int count = 1;
    struct node *temp = head;
    while(pos-1 > count && temp != nullptr){
        temp = temp->next;
        count++;
    }

    if(temp == nullptr){
        cout << "Position not exist\n" << endl;
        delete newnode;
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    cout << "Inserted Successfully\n" << endl;

}

void InsertAtEnd(){                                                                          //INSERT AT END
    int data = input();
    struct node* newnode = Createnode(data);

    if(head == nullptr){
        head = newnode;
        return;
    }
    
    struct node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newnode;

}

//UPDATE
void Update(){
    cout << "Enter the elements to Update: ";
    int el, nel;
    cin >> el;
    cout << "Enter the new element: ";
    cin >> nel;
    struct node *temp = head;
    while(temp != nullptr){
        if(el == temp->data){
            temp->data = nel;
            cout << "Successfully Updated\n" << endl;
            return;
        }
        else{
            temp = temp->next;
        }
    }
    cout << "Element not Found!\n" << endl;
}

//DELETE
void DeleteFromBeg(){                                                                        //DELETE FIRST
    if(head == nullptr){
        cout << "List is Empty!\n" << endl;
        return;
    }

    struct node *temp = head;
    head = head->next;

    delete temp;

    cout << "Deleted Successfully!\n" << endl;
}


void DeleteAtPos(){                                                                          //DELETE AT POSITION
    cout << "Enter the position: ";
    int pos;
    cin >> pos;

    if(pos < 1){
        cout << "Invalid Position\n" << endl;
        return;
    }

    if(head == nullptr){
        cout << "List is Empty!\n" << endl;
        return;
    }

    if(pos == 1){
        DeleteFromBeg();
        return;
    }

    struct node *temp = head;
    int count = 1;

    while(count < pos - 1 && temp != nullptr){
        temp = temp->next;
        count++;
    }

    if(temp == nullptr || temp->next == nullptr){
        cout << "Position does not exist!\n" << endl;
        return;
    }

    struct node *del = temp->next;
    temp->next = del->next;

    delete del;

    cout << "Deleted Successfully!\n" << endl;
}


void DeleteFromEnd(){                                                                        //DELETE THE LAST
    if(head == nullptr){
        cout << "List is Empty!\n" << endl;
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;

        cout << "Deleted Successfully!\n" << endl;
        return;
    }

    struct node *temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    struct node *del = temp->next;
    temp->next = nullptr;

    delete del;

    cout << "Deleted Successfully!\n" << endl;
}


//SEARCH 
void Search(){
    cout << "Enter the data to search: ";
    int d;
    cin >> d;
    int pos = 1;
    struct node *temp = head;
    
    while(temp != nullptr){
        if(temp->data == d){
            cout << d << "found at postion " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Value Not found\n" << endl;

}

//DISPLAY
void Display(){
    struct node *temp = head;
    while(temp != nullptr){
        cout << temp->data << ">" ;
        temp = temp->next;
    }
    cout << "NULL\n" << endl;
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