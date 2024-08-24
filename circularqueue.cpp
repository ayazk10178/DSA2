#include <iostream>
using namespace std;

int queue[100];
int n = 100;
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % n == front) {
        cout << "Queue Overflow" << endl;
    } else {
        if (front == -1) { 
            front = 0;
        }
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
    } else {
        if (front == rear) { 
            front = rear = -1; 
        } else {
            front = (front + 1) % n;
        }
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue elements are: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % n;
        }
        cout << endl;
    }
}

int main() {
    int ch;
    do {
        cout << "1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;
        cout << "3) Display" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                int x;
                cout << "Enter the value to enqueue: ";
                cin >> x;
                enqueue(x);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please enter a valid option." << endl;
                break;
        }
    } while (ch != 4);

    return 0;
}
