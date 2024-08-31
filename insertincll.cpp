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
void insertathead(Node* &last,int d) {
    Node*ptr=new Node(d);
    if(last=NULL) {
        ptr=ptr->next;
        return;
    }
    ptr->next=last->next;
    last->next=ptr;
}
void insertatmid(Node* &last,int d,int pos) {
    int cnt=0;
    Node*temp=last->next;
    while(cnt<pos-1) {
        temp=temp->next;
        cnt++;
    }
Node* ptr=new Node(d);
ptr->next=temp->next;
temp->next=ptr;
    
}
void insertatend(Node* &last,int d) {
    Node*ptr=new Node(d);
    //base case
    if(last==NULL) {
        last=ptr;
        ptr->next=ptr;
    }
    else{
        ptr->next=last->next;
        last->next=ptr;
        last=ptr;
    }
    return;
}
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
    insertathead(last,13);
    printlist(last);
    insertatmid(last,19,2);
    printlist(last);
    insertatend(last,18);
    printlist(last);
    return 0;
}

