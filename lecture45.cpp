#include <iostream>

using namespace std;

class Node{
    public:
    int info;
    Node *next;

    Node(){
        next = NULL;
    }

    Node(int info){
        this->info = info;
        next=NULL;
    }
};

void insert(Node* &head, int val){
    Node *p = new Node();
    p->info = val;
    if(head==NULL){
        head = p;
    }else{
        p->next = head;
        head = p;
    }
}

void display(Node *head){
    cout<<"\nLinked List : ";
    while(head != NULL){
        cout<<head->info<<" ";
        head = head->next;
    }
}

//🙋‍♂ Reverse Linked List 
void reverse(Node* &head){
    //NULL<-1<-2<-3<-4<-5<-head
    Node *prevNode = head;
    Node *current = head->next;
    Node *nextNode = NULL;
    prevNode->next=NULL;
    while(current != NULL){
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }

    head = prevNode;
}

void reverseUsingRecursion(Node* &head, Node *prevNode,Node* cur){

    if(cur == NULL){
        head = prevNode;
        return;
    }
    
    reverseUsingRecursion(head,cur,cur->next);
    cur->next = prevNode;

}

void reverse1(Node * &head){
    reverseUsingRecursion(head,NULL,head);
}

//🙋‍♂ Middle Node 
int findLength(Node * head){
    int  count = 0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

Node* middleNode(Node * head){
    int length = findLength(head);
    int i = 1;
    int middle = length/2 + 1;
    Node *temp = head;
    while(i<middle && temp != NULL) {
        temp = temp->next;
        i++;
    }

    return temp;

}

Node* middleNode1(Node *head) {
    cout<<"enter in function";
    Node *fast = head->next;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    if(fast == NULL) {
        return slow;
    }else{
        return slow->next;
    }
}

int main(){

    int ch,val;
    Node *head = NULL;
    Node *middle = NULL;

    while(1){
        cout<<"\n1.Insert\t2.Display\t3.Reverse\t4.Middle\nEnter your choice : ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"\nEnter a value to insert : ";
                cin>>val;
                insert(head,val);
                break;
            case 2:
                display(head);
                break;
            case 3:
                reverse1(head);
                cout<<"\n"<<head->info<<endl;prac
                cout<<"\nLinked List reversed successfully."<<endl;
                break;
            case 4:
                // middle = middleNode(head);
                middle = middleNode1(head);
                cout<<"\nMiddle Node : "<<middle->info<<endl;
                break;
            default:
                cout<<"\nHappy Coding!"<<endl;
                exit(0);
        }
    }

}