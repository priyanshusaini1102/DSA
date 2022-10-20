#include <iostream>

using namespace std;

class nodetype{
    public:
    int info;
    nodetype *next;
};

void push(nodetype **head, int info){
    nodetype *p = new nodetype();
    p->info = info;
    p->next = NULL;
    if(*head == NULL){
        *head = p;
    }else{
        p->next = *head;
        *head = p;
    }
};

void insertAtPosition(nodetype* &head, int val, int pos){
    nodetype *p =  new nodetype();
    p->info = val;
    p->next=NULL;
    if(pos == 0){
        p->next = head;
        head = p;
    }else{
        int i=0;
        nodetype *temp = head;
        while(temp!=NULL){
            if(i == (pos-1)){
                p->next = temp->next;
                temp->next = p;
                return;
            }
            i++;
            temp = temp->next;
        }

        cout<<"\nThere are only "<<i<<" elements in Linked List.\n";
    }
}

void  display(nodetype *head){
    if(head == NULL){
        cout<<"\nThere is no element in the linked list to display."<<endl;
        return;
    }
    cout<<"\nLinked List : ";
    while(head!=NULL){
        cout<<" "<<head->info<<" ";
        head = head->next;
    }
    cout<<endl;
}

void pop(nodetype **head){
    nodetype *temp = *head;
    if(temp == NULL){
        cout<<"\nThere is no element in the linked list to pop."<<endl;
    }else{
        *head = (*head)->next;
        cout<<endl<<temp->info<<" popped successfully."<<endl;
        delete temp;
    }
}

int main(){
    int ch,val,pos;
    nodetype *head=NULL;

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
                pop(&head);
                break;
            case 3: 
                display(head);
                break;
            case 4: 
                cout<<"\nEnter value to insert :";
                cin>>val;
                cout<<"\nEnter the position : ";
                cin>>pos;

                insertAtPosition(head, val, pos);
                break;
            default: 
                cout<<"\nHappy Coding!\n"<<endl;
                exit(0);
        }
    }
}