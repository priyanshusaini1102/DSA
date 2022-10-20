#include <iostream>
#define MAX_ARRAY 1000

using namespace std;

class Stack{
    public:
    int arr[MAX_ARRAY] = {0};
    int top;

    Stack(){
        top = -1;
    }

    bool pop() {
        if(top == -1){
            cout<<"\nStack is empty!"<<endl;
            return false; 
        }else{
            int temp = arr[top];
            top--;
            return true;
        }
    }

    bool push(int i) {
        if(top == MAX_ARRAY){
            cout<<"\nStack is full!"<<endl;
            return false; 
        }else{
            arr[top+1] = i;
            top++;
            return true;
        }
    }

    int peek(){
        if(top == -1){
            cout<<"\nStack is empty!"<<endl;
            return 0; 
        }else{
            return arr[top];
        }
    }

    void display(){
        if(top == -1){
            cout<<"\nStack is empty!"<<endl;
            return;
        }

        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
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