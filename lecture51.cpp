/************************************************************

    Following is the linked list node structure:
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

************************************************************/
Node<int>* rev(Node<int>* prev,Node<int>* curr){
       if(curr==NULL) return prev;
        Node<int>* res = rev(curr,curr->next);
        curr->next = prev;
    return res;
}

void insertAtHead(Node<int>* &head, int val){
    Node<int> *p = new Node<int>(val);
    p->next = head;
    head = p;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    first = rev(NULL,first);
    second = rev(NULL,second);
    
    int c=0,s=0;
    Node<int> *temp1 = first, *temp2 = second;
    Node<int> *res = NULL;
    while(temp1!=NULL || temp2!=NULL || c!=0){
        int val1 = temp1?temp1->data:0;
        int val2 = temp2?temp2->data:0;
        
        s=val1+val2+c;
        insertAtHead(res,s%10);
        c=s/10;
        temp1=temp1?temp1->next:temp1;
        temp2 = temp2?temp2->next:temp2;
    }
    
    return res;
    
}