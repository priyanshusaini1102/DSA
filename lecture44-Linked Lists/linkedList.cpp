#include <iostream>

using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtPos(Node* &head, int val, int pos){
    Node* temp = head;

    int count = 0;
    Node* p = new Node(val);
    if(pos==0){
        p->next = head;
        head = p;
        return;
    }
    // 1 2 3 4 
    while(count<pos-1){
        temp = temp->next;
        count++;
    }
    Node* temp2 = temp->next;
    temp->next = p;
    p->next = temp2;
}

int main(){
    int val,pos;
    Node* head = NULL;

    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    first->next = second;
    second->next =third;
    third->next = fourth;
    head = first;

    Node *temp = head; 
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<"Enter the value to insert : ";
    cin>>val;
    cout<<"ENter the position on ewhich you want to insert : ";
    cin>>pos;

    insertAtPos(head,val,pos);

    temp = head; 
    swap(temp->data,temp->next->data);
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}