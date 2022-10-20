#include <iostream>
#include <stack>
using namespace std;


int main(){

    stack<int> st;

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
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                cout<<endl<<st.top()<<endl;
                break;
            default:
                cout<<"\n\nHappy Coding!\n\n";
                exit(0);      
        }
    }

}