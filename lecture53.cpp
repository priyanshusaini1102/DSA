/**********************************************************************

    Following is the class structure of the Node class for reference:

    class Node{
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

********************************************************************/
#include<algorithm>
#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };
/*
Node* findMid(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node *slow=head, *fast=head->next;
    cout<<"yha tk si hai for :"<<head->data<<endl;
    while(fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    cout<<"no prblems";
    return slow;
}
*/

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

Node* merge(Node* left, Node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;
    
    if(left->data > right->data){
        swap(left,right);
    }
    
    Node *prev1=left, *curr1=left->next;
    Node *prev2=right, *curr2=right->next;
    while(prev1->next!=NULL && prev2!=NULL){
        if(prev2->data >= prev1->data && prev2->data <=curr1->data){
            prev1->next = prev2;
            prev2->next = curr1;
            prev1 = prev1->next;
            curr1 = (prev1 == curr1)? curr1->next : curr1;
            prev2 = curr2;
            curr2 = curr2?curr2->next:curr2;
        }
        else{
            prev1 = prev1->next;
            curr1 = curr1->next;
        }
        
    }

    if(prev2!=NULL){
        prev1->next = prev2;
    }
    
    return left;
}

Node *mergeSort(Node *head){
    if(head == NULL || head->next == NULL) return head;
    cout<<"mid->"<<head->data<<endl;
    
    Node* mid = findMid(head);
    cout<<"mid ni milra"<<endl;
    
    Node* right = mergeSort(mid->next);
    mid->next = NULL;
    Node* left = mergeSort(head);
    
    Node* res = merge(left,right);
    return res;
   
}

insertAtTail(Node* &head,Node* &tail,int val){
    Node* p = new Node(val);
    if(tail == NULL){
        head = tail = p;
    }else{
        tail->next = p;
        tail = p;
    }
}

int main(){

    Node *head1=NULL,*tail1=NULL;
    Node *head2=NULL,*tail2=NULL;
    
    cout<<"\nInput first linked list : ";
    int val = 0;
    while(1){
        cout<<"Data1: ";
        cin>>val;
        if(val == -1) break;
        insertAtTail(head1,tail1,val);
    }

    Node* temp = head1;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
    cout<<"yaha tk sahi hai";

    Node* mid = findMid(head1);
    cout<<mid->data<<" ";

    Node *res = mergeSort(head1);
    cout<<"\nlinked list: ";
    while(res != NULL){
        cout<<res->data<<" ";
        res = res->next;
    }
    cout<<endl;
    

    // cout<<"\nInput first linked list : ";
    // val=0;
    // while(val != -1){
    //     cout<<"Data2: ";
    //     cin>>val;
    //     insertAtTail(head2,tail2,val);
    // }



}