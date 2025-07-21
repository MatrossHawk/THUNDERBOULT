/*#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}
    
    //insert a node from  head;

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            // Find the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Link the last node to the new node
            newNode->next = head; // Point new node to head
            head = newNode;       // Update head to new node
        }
    }
    //function to insert a node from end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            // Find the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Link last node to the new node
            newNode->next = head; // Point new node to head
        }
}
    // deleting a element from circular linked list
    void deleteFromBeginning() {
        if (!head) {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        Node* temp = head;
        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr; // List becomes empty
        } else {
            Node* last = head;
            // Find the last node
            while (last->next != head) {
                last = last->next;
            }
            head = head->next; // Move head to the next node
            last->next = head; // Update last node's next to new head
            delete temp; // Delete the old head
        }
    }
    // display function
    void display() {
        if (!head) return;

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    //destructor 
    ~CircularLinkedList() {
        if (!head) return;

        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

int main() {
    CircularLinkedList cll;
// creating a object to call all function
    cll.insertAtHead(10);
    cll.insertAtEnd(40);
    cll.insertAtHead(20);
    cll.insertAtEnd(50);
    cll.insertAtHead(30);
    cll.insertAtEnd(60);

    cout << "Circular Linked List: ";
    cll.display();
    cll.deleteFromBeginning();
    cll.display();
    return 0;
} */
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            // Find the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Link the last node to the new node
            newNode->next = head; // Point new node to head
            head = newNode;       // Update head to new node
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            // Find the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Link last node to the new node
            newNode->next = head; // Point new node to head
        }
    }

    void deleteFromBeginning() {
        if (!head) {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        Node* temp = head;
        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr; // List becomes empty
        } else {
            Node* last = head;
            // Find the last node
            while (last->next != head) {
                last = last->next;
            }
            head = head->next; // Move head to the next node
            last->next = head; // Update last node's next to new head
            delete temp; // Delete the old head
        }
    }

    void display() {
        if (!head) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~CircularLinkedList() {
        if (!head) return;

        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                cll.insertAtHead(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 3:
                cll.deleteFromBeginning();
                break;
            case 4:
                cout << "Circular Linked List: ";
                cll.display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

