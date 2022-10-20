#include <iostream>

using namespace std;

int main(){

    int arrStatic[5] = {0};
    int capacity = 2;
    int size;
    cout<<"Enter size of the array : ";
    cin>>size;

    int *arr = new int[capacity];
    if(size >= capacity ){
        capacity=size;
    }

    int *temp = arr;
    arr = new int[capacity];
    delete[] temp;

    for(int i=0;i<=capacity;i++ ){
        arr[i] = i;
    }
    cout<<"\nArray : ";
    for(int i=0;i<=capacity;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;







}