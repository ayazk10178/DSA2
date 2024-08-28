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
  cout<<"Linked list representation:"<<endl;
  print(head);
  deletehead(head);
  cout<<"After deletion:"<<endl;
  print(head);
return 0;
}