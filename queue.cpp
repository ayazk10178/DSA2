#include <iostream>
using namespace std;

int queue[5];
int n = 5;
int front = -1;
int rear = -1;

void Enqueue() {
    if (rear == n - 1) {
        cout << "Overflow:" << endl;
    } else {
        int x;
        cout << "Enter the value to enqueue: ";
        cin >> x;
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = x;
    }
}

void Dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
    } else {
        cout << "Deleted Element: " << queue[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void Display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue Elements are:" << endl;
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
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
        cout << "Enter the choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Enter Valid Choice:" << endl;
                break;
        }
    } while (ch != 4);

    return 0;
}
