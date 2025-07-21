#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the deque

class Deque {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    // Function to insert an element at the end of the deque
    bool insertAtEnd(int value) {
        // Check if the deque is full
        if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
            cout << "Deque is full\n";
            return false;
        }
        // If the deque is empty, initialize front and rear
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0; // Wrap around
        } else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Function to display the deque
    void display() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < MAX; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertAtEnd(10);
    dq.insertAtEnd(20);
    dq.insertAtEnd(30);
    dq.display();

    return 0;
}
