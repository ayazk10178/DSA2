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
Node* mergelist(Node* &a,Node* &b) {
    //create dumpy for merge 
    Node* dummyNode=new Node(-1);
    Node*ptr=dummyNode;
    //traverse the both linked list
    while(a!=NULL & b!=NULL) {
        if(a->data<=b->data) {
            ptr->next=a;
            a=a->next;
        }
        else {
            ptr->next=b;
            b=b->next;
        }
        ptr=ptr->next;
    }
    //condition if any list still remain to  merge
    if(a!=NULL) {
        ptr->next=a;
    }
    else {
        ptr->next=b;
    }
    return dummyNode->next;
}
void print(Node* head) {
    Node*ptr=head;
    while(ptr!=NULL) {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
int main() {
    Node* a=new Node(1);
    a->next=new Node(3);
    a->next->next=new Node(5);

    Node* b=new Node(2);
    b->next=new Node(4);
    b->next->next=new Node(6);
    print(a);
    print(b);
    Node* list=mergelist(a,b);
    print(list);
    return 0;
}