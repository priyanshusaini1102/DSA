#include <iostream>

using namespace std;

class A{
    public:
    int size;
    int *arr;

    //Simple Costructor

    A(){};

    //Parameterised Constructor

    A(int size){
        this->size = size;
        arr = new int[size+1];
        for(int i=0;i<=this->size;i++){
            this->arr[i] = i;
        }
    }

    A(int size, int *arr){
        this->size;
        this->arr = arr;
    }

    //Copy Constructor - same as default copy constructor which leads to shallow copy. 
    /*
    A(A &obj){
        this->size = obj.size;
        this->arr = obj.arr;
    }
    */

    A(A &obj){
        this->size = obj.size;
        this->arr = new int[size+1];
        for(int i=0;i<=size;i++){
            this->arr[i] = obj.arr[i];
        }
    }

    void getArray(){
        
        cout<<"\nArray : ";
        for(int i=0; i<=this->size;i++){
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;

    }

};

int main(){

    A a(5);
    a.getArray();
    a.arr[4] = 12;
    a.getArray();

    A copyA(a);
    copyA.getArray();
    a.arr[5] = 15;
    copyA.getArray();
    a.getArray();

}