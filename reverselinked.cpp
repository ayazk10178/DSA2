#include<iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void reversell(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    
    while (curr != NULL) {
        forward = curr->next; 
        curr->next = prev;    
        prev = curr;         
        curr = forward;       
    }
    
    head = prev; // Update head to the new first node
}

void print(Node* head) {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    first->next = second;
    second->next = third;
    third->next = fourth;

    Node* head = first;

    cout << "Original list: ";
    print(head);

    reversell(head);

    cout << "Reversed list: ";
    print(head);
    
    return 0;
}
