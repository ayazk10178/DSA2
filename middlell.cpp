#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
    Node(int data) {
        this->data=data;
        this->next=NULL;
    }
};
int middlelist(Node* &head) {
    if(head==NULL) {
        return -1;
    }
    Node* ptr=head;
    Node*temp=head;
    //move ptr by 2 and temp by 1
   while (ptr != nullptr && ptr->next != nullptr) {
    ptr=ptr->next->next;
    temp=temp->next;

    }
    return temp->data;
}
void print(Node* &head) {
    Node*ptr=head;
    while(ptr!=NULL) {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
int main() {
    Node*first=new Node(1);
    Node*second=new Node(2);
    Node*third=new Node(3);
    Node*fourth=new Node(4);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;
    Node*head=first;
    print(head);
      int middleValue = middlelist(head);
      cout << "Middle value: " << middleValue << endl;
      print(head);
        while (head != nullptr) {
        Node* prev = head;
        head = head->next;
        delete prev;
    }

    return 0;
}
