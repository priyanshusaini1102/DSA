#include <iostream>

using namespace std;

int fun(int a, int b){
    if(a==b)
        return 0;
    if(a>b)
        return fun(a-1,b);
    if(b>a)
        return 1+fun(a+1,b-1);  //accolite
    else
        return 3+fun(a,b);
    return 1;
}

int func(){
    return 1;
}

int main(){
    cout<<"ans:"<<func();
    int ans = fun(13,2);


}