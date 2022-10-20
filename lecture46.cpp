#include<iostream>
#include <map>
using namespace std;

//Lecture 46 & 47

class Node{
    public:
    int info;
    Node* next;

    Node(int info){
        this->info = info;
        this->next = NULL;
    }
};

void insert(Node* &head, int val){
    Node *p = new Node(val);
    p->next = head;
    head = p;
}

void display(Node* head){
    cout<<"\nLinked List :";
    while(head!=NULL){
        cout<<head->info<<" ";
        head = head->next;
    }
}

Node* reverseInK(Node* head, int k){

    if(head==NULL){
        return NULL;
    }
    int count=0;

    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;

    //1->2->3->4->5->6->7->8->9->10->null
    while(cur!=NULL && count<k) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur=next;

        count++;
    }

    head->next = reverseInK(next, k);

    return prev;

}

void makeCircular(Node* &head){
    if(head == NULL){
        return;
    }
    Node *temp = head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next = head;
}

//Detection of circular linked list
bool isCircular(Node* head){
    Node *temp = head->next;

    while(temp!=NULL && temp->next!=head){
        temp = temp->next;
    }

    if(temp==NULL){
        return false;
    }else{
        return true;
    }
}

void makeItLinear(Node* head){

    Node* temp = head->next;

    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next=NULL;
}

void makeLoop(Node* &head, int pos){
    int i=0;
    Node*tail=NULL;
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    tail=temp;

    temp=head;
    while(i<pos){
        temp = temp->next;
    }
    tail->next=temp;
}

// 🙋‍♂️detect loop using map stl
/*
bool detectLoop(Node* head){
    map<Node*,bool> isReached;

    Node* temp = head;

    while(temp != NULL){
        isRea
    }

    auto it=isReached.find(head);
    while(temp != NULL){
        isReached[temp] = true;
        it = isReached.find(temp->next);
        if((it->second) == true){
            cout<<"\nLoop at "<<(it->second)<<endl;
            return true;
        }
        temp=temp->next;
    }

    return false;
}
*/

Node* detectLoop2(Node *head){
    Node* slow = head;
    Node *fast = head->next;
    int flag = 0;
    while(fast!=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast == slow){
            flag=1;
           break;
        }
    }

    if(fast->next == head){
        return fast;
    }
    
    if(flag==1){
        slow = head;
        while(fast != slow){
            slow=slow->next;
            fast = fast->next;
        }
        return fast;
    }

    return NULL;
}

int main(){

    int ch,val;
    Node* head = NULL;
    Node *loopAt = NULL;

    while(1){
        cout<<"\n1.Insert\n2.Display\n3.Reverse Linked List in K groups\n4.Make it circular\n5.Make it linear\n6.Is Circular?\n7.Insert loop\n8.detect loop\n9.Remove loop\nEnter your choice : ";
        cin>>ch;

        if(ch>1 && head==NULL){
            cout<<"\nThe linked list is empty."<<endl;
            continue;
        }

        switch(ch){
            case 1: 
                cout<<"\nEnter value to insert : ";
                cin>>val;
                insert(head,val);
                break;
            case 2: 
                display(head);
                break;
            case 3:
                cout<<"Enter the value of k : ";
                cin>>val;
                head = reverseInK(head,val);
                break;
            case 4:
                if(!isCircular(head) ){
                    makeCircular(head);
                }else{
                    cout<<"\nThe linked list is already circular in nature."<<endl;
                }
                break;
            case 5:
                if(isCircular(head) ){
                    makeCircular(head);
                }else{
                    cout<<"\nThe linked list is already linear in nature."<<endl;
                }
                break;
            case 6:
                if(head==NULL){
                    cout<<"\nLinked List is Empty!"<<endl;
                    break;
                }
                if(isCircular(head)){
                    cout<<"\nYes, The linked list is circular."<<endl;
                }else{
                    cout<<"\nNo,The linked list is not circular."<<endl;
                }
                break;
            case 7:
                cout<<"\nEnter the position to insert loop : ";
                cin>>val;
                if(!isCircular(head)){
                    makeLoop(head,val);
                }else{
                    cout<<"\nThe linked list already circular or have any loop."<<endl;
                }
                break;
            case 8:
                loopAt = detectLoop2(head);
                if(loopAt != NULL){
                    cout<<"\nYes loop exits"<<endl;
                }else{
                    cout<<"\nNo loop exits"<<endl;
                }
                break;
            case 9:
                if(loopAt == NULL){
                    cout<<"\nfirstly detects the loop"<<endl;
                    break;
                }
                loopAt->next = NULL;
                loopAt = NULL;
                cout<<"\nLoop removed successfully"<<endl;
                break;
            default:
                cout<<"\nHappy Coding!\n"<<endl;
                exit(0);
        }
    }

}