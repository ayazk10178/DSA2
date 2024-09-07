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
Node* sortList(Node* &head){
    int zerocnt=0;
    int firstcnt=0;
    int secondcnt=0;
    Node*ptr=head;
    while(ptr!=NULL) {
        if(ptr->data==0) {
            zerocnt++;
        }
        else if(ptr->data==1) {
            firstcnt++;
        }
        else {
            secondcnt++;
        }
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr!=NULL) {
        if(zerocnt!=0){
            ptr->data=0;
            zerocnt--;
        }
        else if(firstcnt!=0) {
            ptr->data=1;
            firstcnt--;
        }
        else {
            ptr->data=2;
            secondcnt--;
        }
        return head;
    }
}
void printlist(Node* &head) {
    Node*temp=head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
    Node* first = new Node(0);
    Node* second = new Node(1);
    Node* third = new Node(2);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);
    Node* sixth = new Node(2);
    first->next = second;
    second->next = third;
    third->next =fourth;
    second->next = third;
    third->next = fourth;
    fifth->next = sixth;
    sixth->next=NULL;
    Node* head = first;
    printlist(head);
    sortList(head);
    printlist(head);
        Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}