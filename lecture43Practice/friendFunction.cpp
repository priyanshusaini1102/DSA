#include <iostream>

using namespace std;

class A{
    private:
    int a,b;

    public:
    A(int a,int b){
        this->a = a;
        this->b = b;
    }
    void print(){
        cout<<"\nSum :"<<a+b<<endl;
    }

    friend void multiply(A &x);
    friend void friendFuncWithoutArgs();
};

void multiply(A &x){
    cout<<"\nProduct :"<<x.a*x.b<<endl;
}

void friendFuncWithoutArgs(){
    A y(5,3);
    y.a = 21;
    cout<<"\nA : "<<y.a<<endl;
}



int main(){

    A m(1,2);


    multiply(m);
    friendFuncWithoutArgs();


}