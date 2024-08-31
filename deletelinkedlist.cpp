#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int data) {
  this->data=data;
  this->next=NULL;
}
};
void deletehead(Node* &head) {
    if(head==NULL) {
        return;
    }
    Node*ptr=head;
    head=head->next;
    delete ptr;
}
void deletemiddle(Node* &head,int pos) {
    Node*prev;
    Node*ptr=head;
    //first make base case
    if(head==NULL) {
        return;
    }
    for(int i=0;i!=pos;i++) {
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr!=NULL) {
        prev->next=ptr->next;
        delete ptr;
    }
}
void deletelast(Node* &head) {
    if(head==NULL) {
        return;
    }
    if(head->next==NULL) {
        delete head;
        return ;
    }
    //more than one node
    Node*ptr=head;
    while(ptr->next->next!=NULL) {
        ptr=ptr->next;
    }
    delete (ptr->next);
    ptr->next=NULL;
    return;

}
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next; 
    }
    cout << endl;
}
int main() {
  Node* head=new Node(3);
  head->next=new Node(12);
  head->next->next=new Node(15);
  head->next->next->next=new Node(18);
    head->next->next->next->next=new Node(21);
      head->next->next->next->next->next=new Node(25);
  cout<<"Linked list representation:"<<endl;
  print(head);
  deletehead(head);
  cout<<"After deletion:"<<endl;
  print(head);
  deletemiddle(head,3);
  cout<<"After deletion of middle:"<<endl;
  print(head);
  deletelast(head);
  cout<<"Last deletion:"<<endl;
  print(head);
return 0;
}