#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack {
    public:
    Node* head;

    Stack(){
        head = NULL;
    }

    bool push(int data){
        Node *p = new Node(data);
        if(head == NULL){
            head = p;
        }else{
            p->next = head;
            head = p;
        }

        return true;
    }

    bool pop(){
        if(head == NULL){
            cout<<"\nStack is empty!"<<endl;
            return false;
        }else{
            Node *temp = head;
            head = head->next;
            delete temp;
            return true;
        }
    }

    int peek(){
        if(head == NULL){
            cout<<"\nStack is empty!"<<endl;
            return 0;
        }else{
            return head->data;
        }
    }

    void display(){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }



    

};


int main(){

    Stack st;

    int ch,val;
    bool res = false;
    string msg = "";

    while(1){
        cout<<"\n1.PUSH\t2.POP\t3.PEEK\t4.DISPLAY\nEnter your choice :";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"\nEnter value to push : ";
                cin>>val;
                res = st.push(val);
                msg = res? "OK" : "ERROR";
                cout<<msg<<endl;
                break;
            case 2:
                res = st.pop();
                msg = res? "OK" : "ERROR";
                cout<<msg<<endl;
                break;
            case 3:
                cout<<endl<<st.peek()<<endl;
                break;
            case 4:
                st.display();
                break;
            default:
                cout<<"\n\nHappy Coding!\n\n";
                exit(0);      
        }
    }

}