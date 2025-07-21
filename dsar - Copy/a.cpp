/* #include<iostream>
#include<algorithm>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int value){
    this->data = value;
    this->next = NULL;
}


};
Node* insertAttail(int value, Node* &head, Node* &tail){
    if(head==NULL && tail==NULL)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;


        }
        return head;
}




Node* insertAthead(int value,Node* &head, Node* &tail){
    if(head==NULL && tail==NULL)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
else 
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;

}
return head;
} 
void print(Node* head){
Node* temp = head;

while(temp != NULL)
    {
    cout<< temp -> data <<" ->";
    temp =  temp-> next;

    }
cout<<"NULL"<<endl;

}
int getlength( Node* head){
    int len =0;
    Node* temp = head;
    while( temp!= NULL ){
        temp = temp->next ;
        len ++;
    }
    return len;
}

void insertAtPosition( int position, int value,Node* &head, Node* tail){
int length = getlength(head);
if( position == 1){
head = insertAthead(value,head,tail);
}
else if(position == length+1){
    insertAttail(value,head,tail);
}
else{
Node* temp = head;
for(int i=0; i<position; i++){
    temp = temp->next;
}
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
}
bool serachll( int target, Node* head){
    Node* temp = head;
    while( temp!=NULL ){
        if(temp->data == target){
            return true;
    }
    temp = temp->next;
    }
    return false;
}

void ddel( int position, Node* &head, Node* tail){
// linked list is empty
if( head==NULL && tail==NULL ){

cout<< " no node is pesent " <<endl;
return;
}
// linked list only have node is present
    if( head==tail ){
    Node* temp = head;
    head = NULL;
    tail == NULL;
    delete temp;
    return;
}
// linked list is not single
else{
        if(position == 1){
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            Node* pre = head;
            for( int i=0; i<position-2; i++){
                    pre = pre -> next;      


            }
            Node* curr = pre -> next;
            Node* forward = curr->next;
            pre->next = forward;
            curr->next = NULL;
            delete curr;
        }
        }


}



int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    
    head=insertAttail(101,head,tail);
    print(head);
    head = insertAttail(202,head,tail);
    print(head);
    head = insertAttail(302,head,tail);
    print(head);
// print(head);

insertAtPosition(1,42,head,tail);
print(head);
cout<<serachll(199,head);
print(head);
ddel(1,head,tail);
print(head);
return 0;



    
}*/
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

Node* insertAttail(int value, Node*& head, Node*& tail) {
    Node* newNode = new Node(value);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

Node* insertAthead(int value, Node*& head, Node*& tail) {
    Node* newNode = new Node(value);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int getlength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int position, int value, Node*& head, Node*& tail) {
    int length = getlength(head);
    if (position == 1) {
        head = insertAthead(value, head, tail);
    } else if (position == length + 1) {
        insertAttail(value, head, tail);
    } else {
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

bool searchll(int target, Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void ddel(int position, Node*& head, Node*& tail) {
    if (head == NULL) {
        cout << "No node is present." << endl;
        return;
    }
    
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* pre = head;
        for (int i = 1; i < position - 1; i++) {
            pre = pre->next;
        }
        Node* curr = pre->next;
        if (curr) {
            pre->next = curr->next;
            delete curr;
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice, value, position;

    do {
        cout << "Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Node\n";
        cout << "5. Search for a Value\n";
        cout << "6. Print List\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                head = insertAthead(value, head, tail);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                head = insertAttail(value, head, tail);
                break;
            case 3:
                cout << "Enter position and value to insert: ";
                cin >> position >> value;
                insertAtPosition(position, value, head, tail);
                break;
            case 4:
                cout << "Enter position to delete: ";
                cin >> position;
                ddel(position, head, tail);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchll(value, head)) {
                    cout << value << " is found in the list." << endl;
                } else {
                    cout << value << " is not found in the list." << endl;
                }
                break;
            case 6:
                print(head);
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}
