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

Node* findMid(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverse(Node* head){
    Node *prev = NULL;
    Node* curr = head;
    Node* nxt = NULL;

    while(curr != NULL){
        nxt = curr->next;

        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool checkPallindrome(Node* head){
    Node* mid = NULL;
    Node* head2 = NULL;

    mid = findMid(head);
    mid->next = reverse(mid->next);
    head2 = mid->next;
    while(head!=mid){
        if(head->info!=head2->info){
            cout<<head->info<<" "<<head2->info<<endl;
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    return true;
}

int main(){
    int ch,val;
    Node *head=NULL;
    Node* mid = NULL;

    while(1){
        cout<<"\n1.Push\t2.Pop\t3.Display\t4.Find middle element.\t5.Reverse from middle\nEnter your choice : ";
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
            case 4: 
                mid = findMid(head);
                cout<<"\nmiddle : "<<mid->info<<endl;
                break;
            case 5:
                mid->next =  reverse(mid->next);
                break;
            case 6:
                if(checkPallindrome(head)){
                    cout<<"\nYes, the linked list is pallindrome.\n"<<endl;
                }else{
                    cout<<"\nNo, the list is not pallindrome"<<endl;
                }
                break;

            default: 
                exit(0);
        }
    }


}