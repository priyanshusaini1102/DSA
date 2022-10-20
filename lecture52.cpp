#include <bits/stdc++.h> 
#include <iostream>

using namespace std;
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
            this->random=NULL;
        }
    };

void insertAtTail(LinkedListNode<int>* &head, LinkedListNode<int>* &tail, int val){
    LinkedListNode<int> *p = new LinkedListNode<int>(val);
    if(tail==NULL){
        head = tail = p;
    }else{
        tail->next = p;
        tail = p;
    }
}

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(head == NULL || head->next == NULL) return head;
    LinkedListNode<int> *resHead=NULL, *resTail=NULL, *temp1=head,*temp2=NULL,*nxt1=NULL,*nxt2=NULL;
    while(temp1!=NULL){
        insertAtTail(resHead,resTail,temp1->data);
        temp1 = temp1->next;
    }

    temp1=head;
    temp2=resHead;
    while(temp1!=NULL){
        nxt1=temp1->next;
        nxt2=temp2->next;
        temp1->next = temp2;
        temp1 = temp1->next;
        temp1->next = nxt1;
        temp1=nxt1;
        temp2=nxt2;
    }

    temp1=head;
    while(temp1!=NULL){
        temp1->next->random = temp1->random->next;
        temp1 = temp1->next->next;
    }

    temp2=resHead;
    while(temp2!=NULL){
        temp2->next = temp2->next?temp2->next->next:temp2->next;
        temp2 = temp2->next;
    }
    return resHead;
    
}


/*
LinkedListNode* copyList(LinkedListNode *head)
    {
        //step 1: Create a Clone List
        LinkedListNode* cloneHead = NULL;
        LinkedListNode* cloneTail = NULL;
        
        LinkedListNode* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        LinkedListNode* originalNode = head;
        LinkedListNode* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            LinkedListNode* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            
            if(originalNode -> arb != NULL) {
                cloneNode -> arb = originalNode -> arb -> next;
            }
            else
            {
                cloneNode -> arb  = NULL;
            }
            
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        //step 4: revert step 2 changes
        LinkedListNode* original = head;
        LinkedListNode* copy = cloneHead;
        
         while (original && copy)
            {
                original->next =
                 original->next? original->next->next : original->next;
         
                copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
                copy = copy->next;
            }

        // step 5 answer return
        return cloneHead;
    }
*/
int main(){
    // 1 2 2 0 3 4 4 4 5 1 -1
    /*
    LinkedListNode<int> *p1 = new LinkedListNode<int>(1);
    LinkedListNode<int> *p2 = new LinkedListNode<int>(2);
    LinkedListNode<int> *p3 = new LinkedListNode<int>(3);
    LinkedListNode<int> *p4 = new LinkedListNode<int>(4);
    LinkedListNode<int> *p5 = new LinkedListNode<int>(5);

    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    p4->next=p5;

    p1->random = p3;
    p2->random = p1;
    p3->random = p5;
    p4->random = p5;
    p5->random = p2;
    */
    LinkedListNode<int> *p1 = new LinkedListNode<int>(1);
    // LinkedListNode<int> *p2 = new LinkedListNode<int>(2);
    p1->random = p1;


    LinkedListNode<int> *res = cloneRandomList(p1);

    LinkedListNode<int>* temp1 = res;
    while(temp1!=NULL){
        cout<<temp1->data<<" ,"<<(temp1->random)->data<<" | ";
        temp1=temp1->next;
    }

}
