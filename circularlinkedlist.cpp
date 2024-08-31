#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printlist(Node* last) {
    if (last == NULL) {
        return;
    }
    
    Node* head = last->next;
    do {
        cout << head->data << " ";
        head = head->next;
    } while (head != last->next);
    cout << endl;
}

int main() {
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    first->next = second;
    second->next = third;
    third->next = first;

    Node* last = third;
    printlist(last);

    return 0;
}

