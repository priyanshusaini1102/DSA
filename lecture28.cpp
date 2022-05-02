#include <iostream>

using namespace std;

int main(){
/*
    int a = 5;
    int& b = a;
    b++;
    cout<<a<<endl;

    int* ptr = &a;
    cout<<*ptr<<endl;
*/

/*
    int* ptr = new int;
    *ptr = 21;
    (*ptr)++;

    cout<<*ptr<<endl;
    cout<<"address : "<<endl;
    cout<<ptr<<endl;
    *ptr++;
    cout<<"after increment : "<<ptr<<endl;
*/

// ~~~~~~ Dynamic Allocation of array ~~~~~~//
    int size = 0;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int* arrPtr = new int[size];

    for(int i=0; i<size; i++){
        cin>>arrPtr[i];
    }


    for(int i=0; i<size; i++){
        cout<<arrPtr[i]<<" ";
    }
    cout<<endl;

}