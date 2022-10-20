#include <iostream>
#include <algorithms>

using namespace std;

class Node{
    public:
    int info;
    Node *next;

    Node(){};
    Node(int info){
        this->info = info;
        this->next = NULL;
    };
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

// replace values
/*
void sort012(Node* &head){
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    Node* curr = head;
    while(curr!=NULL){
        switch(curr->info){
            case 0: 
                countZero++;
                break;
            case 1:
                countOne++;
                break;
            case 2:
                countTwo++;
                break;
        }
        curr = curr->next;
    }

    curr = head;

    while(curr!=NULL){
        if(countZero > 0){
            curr->info = 0;
            countZero--;
        }else if(countOne > 0){
            curr->info = 1;
            countOne--;
        }else{
            curr->info = 2;
            countTwo--;
        }
        curr = curr->next;
    }

}
*/
void insertAtTail(Node* &tail, Node* &n){
    tail->next = n;
    tail = n;
    n->next = NULL;
}

void sort012(Node* &head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = head;
    Node* curr = NULL;
    while(temp!=NULL){
        curr = temp->next;
        switch(temp->info){
            case 0:
                insertAtTail(zeroTail,temp);
                break;
            case 1:
                insertAtTail(oneTail,temp);
                break;
            case 2:
                insertAtTail(twoTail,temp);
                break;
        }
        temp = curr;
    }

    /*
    -1(zh) -> 0 -> 0 -> 0(zt) -> x
    -1(oh) -> 1 -> 1 -> 1(ot) -> x
    -1(th) -> 2 -> 2 -> 2(tt) -> x
    */

    oneTail->next = twoHead->next;
    zeroTail->next = oneHead->next;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

void merge(Node* &head1, Node* &head2){
    /*
    head1->0->2->x
    head2->1->3->5->7->x
    */

  if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    if(head1->info > head2->info){
        swap(head1,head2);
    }
    
   Node* prev = head1;
   Node* curr = head1->next;
   Node* prev2 = head2;
   Node* curr2 = head2->next;

   while(curr != NULL && prev2!=NULL ){
    if(prev2->info <= curr->info && prev2->info >= prev->info) {
        prev->next = prev2;
        prev2->next = curr;
        prev2 = curr2;
        if(curr2!=NULL){
            curr2 = curr2->next;  
        }
        
    }
       if(prev->next!=NULL){
        prev = prev->next;
       }
       
        if(prev == curr && curr!=NULL){
           curr = curr->next; 
        }
        
   }

   if(prev2!=NULL){
    prev->next = prev2;
   }
    
    return head1;

}


int main(){
    int ch,val;
    Node *head=NULL;

    while(1){
        cout<<"\n1.Push\t2.Display\t3.Sort 0,1 and 2\nEnter your choice : ";
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
                sort012(head);
                break;
            case 4: 
                
            default: 
                cout<<"\nHappy Coding!\n"<<endl;
                exit(0);
        }
    }

}