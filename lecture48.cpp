#include <iostream>
#include<bits/stdc++.h>

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

void  display(nodetype *head){
    cout<<"\nLinked List : ";
    while(head!=NULL){
        cout<<" "<<head->info<<" ";
        head = head->next;
    }
    cout<<endl;
}

void removeDuplicatesinSortedLL(nodetype* &head){
    nodetype* curr = head;
    nodetype* temp = NULL;
    while(curr != NULL){
        if(curr->next != NULL && curr->next->info == curr->info){
            temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }else{
            curr = curr->next;
        }
    }

}

void removeDuplicates(nodetype * &head){
    nodetype* curr = head;
    nodetype* next = head;
    nodetype *temp = NULL;

    while(curr != NULL){
        next=curr;
        while(next->next != NULL){
            if(next->next->info == curr->info){
                temp = next->next;
                next->next = next->next->next;
                delete temp;
            }else{
                next = next->next;
            }
        }
        curr = curr->next;
    }
}


//✅ Opitimised solution 
void removeDuplicates1(nodetype* &head)
{
    // Write your code here
     if(head==NULL || head->next==NULL)return;
    unordered_map<int,int> m;
    nodetype *curr=head;
    m[curr->info]=1;
    nodetype *prev=curr;
    curr=curr->next;
    while(curr != NULL)
    {
        if(m[curr->info]){
            prev -> next = curr -> next;
            free(curr);
        }
        else{
            m[curr->info]=1;
            prev=curr;
        }
        curr=prev->next;
    }
}

int main(){
    int ch,val;
    nodetype *head=NULL;

    while(1){
        cout<<"\n1.Push\t2.Display\t3.Remove duplicates\nEnter your choice : ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"\nEnter the value to insert : ";
                cin>>val;
                push(&head,val);
                break;
            case 2: 
                display(head);
                break;
            case 3: 
                removeDuplicates1(head);
                break;
            default: 
                cout<<"\nHappy Coding!\n"<<endl;
                exit(0);
        }
    }


}