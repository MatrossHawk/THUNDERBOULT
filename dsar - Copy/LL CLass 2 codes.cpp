#include <iostream>
using namespace std;

class Node{
  public: 
  int data;
  Node* prev;
  Node* next;

  Node(int value) {
    data = value;
    prev = NULL;
    next = NULL;
  }
};

void insertAtHead(int value, Node* &head, Node* &tail) {

  if(head == NULL && tail == NULL) {
    //iska mtlb, main firstb node create krne wala hu 
    Node* newNode = new Node(value);
    head = newNode;
    tail= newNode;
  }
  else {
    
    Node* newNode = new Node(value);
    newNode->next = head;
    head -> prev = newNode;
    head = newNode;
  }
}

void print(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp ->next;
  }
  cout << "NULL"<<endl;
}

void printReverse(Node* tail) {
  Node* temp = tail;
  while(temp != NULL) {
    cout << temp->data <<"->";
    temp = temp->prev;
  }
  cout << "NULL" << endl;
}

void insertAtTail(int value, Node* &head, Node* &tail ){
  
  if(head == NULL && tail == NULL) {
    
    Node* newNode = new Node(value);
   
    head = newNode;
 
    tail = newNode;
  }
  else {
    Node* newNode = new Node(value);
    
    newNode->prev = tail;
    
    tail->next = newNode;
  
    tail = newNode;
  }
}

int getLength(Node* &head) {
  Node* temp = head;
  int count = 0;
  while(temp != NULL) {
    count++;
    temp = temp ->next;
  }
  return count;
}

void insertAtPosition(int position,int value, Node* &head, Node* &tail) {
  
  int len = getLength(head);
  if(position == 1) {
 
    insertAtHead(value, head,tail);
  }
  else if(position == len+1) {
   
    insertAtTail(value, head, tail);
  }
  else {
    
    Node* temp = head;
  
    for(int i=0; i<position-2; i++) {
      temp = temp ->next;
    }
   
    Node* newNode = new Node(value);
   
    Node* forward = temp->next;
  
    newNode->prev = temp;
    temp->next = newNode;
    forward->prev = newNode;
    newNode->next = forward;
  }
  

}

bool searchElement(Node* head, int target) {
  Node* temp = head;
  while(temp != NULL) {
    if(temp ->data == target) {
      return true;
    }
    temp = temp -> next;
  }
  
  return false;
}


void deleteFromPosition(int position, Node* &head, Node* &tail) {
  int length = getLength(head);

  if(head == NULL && tail == NULL) {
    cout << "no nodes to delete" << endl;
    return;
  }
  else if(head == tail) {
    
    Node* temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
  }
  else if(position == 1) {
    
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
  }
  else if(length == position) {
  
    Node* temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
  }
  else {

    Node* backward = head;
    for(int i=0; i<position-2; i++) {
      backward = backward -> next;
    }
    Node* curr = backward->next;
    Node* forward = curr->next;


    backward->next = forward;
    forward->prev = backward;
    
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;

  }
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Position\n";
        cout << "5. Print List\n";
        cout << "6. Print Reverse List\n";
        cout << "7. Search Element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(value, head, tail);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                insertAtTail(value, head, tail);
                break;
            case 3:
                cout << "Enter position and value to insert: ";
                cin >> position >> value;
                insertAtPosition(position, value, head, tail);
                break;
            case 4:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteFromPosition(position, head, tail);
                break;
            case 5:
                print(head);
                break;
            case 6:
                printReverse(tail);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchElement(head, value)) {
                    cout << value << " found in the list." << endl;
                } else {
                    cout << value << " not found in the list." << endl;
                }
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
