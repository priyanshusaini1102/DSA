#include <iostream>

using namespace std;

class Node{
    public:
    int info;
    Node *next;
};

void push(Node **head, int info){
    Node *p = new Node();
    p->info = info;
    p->next = NULL;
    if(*head == NULL){
        *head = p;
    }else{
        p->next = *head;
        *head = p;
    }
};

void  display(Node *head){
    cout<<"\nLinked List : ";
    while(head!=NULL){
        cout<<" "<<head->info<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    int ch,val;
    Node *head=NULL;

    while(1){
        cout<<"\n1.Push\t2.Pop\t3.Display\nEnter your choice : ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"\nEnter the value to insert : ";
                cin>>val;
                push(&head,val);
                break;
            case 2: 
                cout<<"Pop ";
                break;
            case 3: 
                display(head);
                break;
            default: 
                exit(0);
        }
    }


}