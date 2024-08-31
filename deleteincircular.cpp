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
void deletehead(Node* &last) {
    //base case
    //lets suppose list is empty no node
    if(last==NULL) {
        return;
    }
    Node*ptr=last->next;
    if(ptr==last) {
        delete ptr;
        last=NULL;
    }
    else {
        ptr=last->next;
        last->next=ptr->next;
        delete ptr;
    }
}
void deletemid(Node* &last,int pos) {
    Node*prev;
    Node* ptr=last->next;
    if(last==NULL) {
        return;
    }
    for(int i=0;i!=pos;i++) {
        prev=ptr;
        ptr->next=ptr;
        if(ptr==last->next) {
            return;
        }
    }
    if(ptr==last->next) {
        return;
        if(ptr==last) {
            last=prev;
        }
        delete ptr;
    }
}
int main() {
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth=new Node(4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next=first;
    Node* last = fourth;
    printlist(last);
    deletehead(last);
    printlist(last);
    deletemid(last,2);
    printlist(last);
    return 0;
}

