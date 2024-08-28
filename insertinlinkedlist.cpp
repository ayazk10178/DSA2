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
void insertathead(Node* &head,int data) {
  Node*temp=new Node(data);
  temp->next=head;
  head=temp;
}
void insertatmiddle(Node* &head,int data,int position) {
  Node*temp=head;
  int cnt=1;
  while(cnt<position-1) {
    temp=temp->next;
    cnt++;
  }
  //creating a new node
  Node* ptr=new Node(data);
  ptr->next=temp->next;
  temp->next=ptr;
}
void insertatend(Node* &head,int data) {
  Node*temp=new Node(data);
  Node* ptr=head;
  while(ptr->next!=NULL) {
    ptr=ptr->next;
  }
  ptr->next=temp;
  temp->next=NULL;
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
  Node* head=new Node(1);
  head->next=new Node(2);
  head->next->next=new Node(3);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(5);
  cout<<"Linked list representation:"<<endl;
  print(head);
  insertathead(head,0);
  cout<<"Linked list after insertion:"<<endl;
  print(head);
  insertatmiddle(head,25,4);
  cout<<"Linked list after middle insertion:"<<endl;
  print(head);
  insertatend(head,6);
  cout<<"Linked list after last insertion:"<<endl;
  print(head);
  return 0;
    }
