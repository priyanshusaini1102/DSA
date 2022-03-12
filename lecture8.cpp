#include <iostream>
#include <stdlib.h>

using namespace std;

int fact(int num){
    int fact=1;
    for(int i=1;i<=num;i++){
        fact*=i;
    }
    return fact;
}

int nCr(int n, int r){
    int ans = fact(n)/(fact(r)*fact(n-r));
    return ans;
}

int AP(int n){
    int ans = (3 * n) + 7;
    return ans;
}

int countSetBit(int num){
    int count = 0;
    while(num){
        if(num&1){
            count++;
        }
        num = num >> 1;
    }
    return count;
}

int countAandB(int a, int b){
    
    int ans = countSetBit(a)+countSetBit(b);
    return ans;
}

void fibonacci(int num){
    int a=0;
    int b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=1;i<=num;i++){
        int c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }

}

int main(){
    // int n;
    // while(1){
    // cout << "Enter 1 to exit.\n";

    // if(n == 1){
    //     cout << "exit krega...";
    //     return 0;
    // }
    // }

    // while(1){
    //     cout<<"Enter value of n :";
    //     cin>>n;
    //     switch (n)
    //     {
    //     case 1:
    //         return 0;
    //         break;
    //     case 2: continue;
    //     default:
    //         return 0;
    //     }
    // }

    //Mini Calculator
    // int a,b;
    // char op;
    // cout<< "Enter expression(for ex., a+b):";
    // cin>>a>>op>>b;
    // cout<<a<<op<<b<<"=";
    // switch (op)
    // {
    // case '+' :
    //     cout<<(a+b)<<endl;
    //     break;
    // case '-' :
    //     cout<<(a-b)<<endl;
    //     break;
    // case '*' :
    //     cout<<(a*b)<<endl;
    //     break;
    // case '/' :
    //     cout<<(a/b)<<endl;
    //     break;
    // default:
    //     break;
    // }

    //To count Notes using switch
    // int amount,note100,note50,note20,note1;
    // cout<<"Enter the amount :";
    // cin>>amount;
    // switch (1)
    // {
    // case 1:
    //     note100 = amount/100;
    //     amount = amount%100;
    // case 2:
    //     note50 = amount/50;
    //     amount = amount%50;
    // case 3:
    //     note20 = amount/20;
    //     amount = amount%20;
    // case 4:
    //     note1 = amount/1;
    //     amount = amount%1;
    // default:
    //     break;
    // }
    // cout<<"Number of 100 Notes : "<<note100<<endl;
    // cout<<"Number of 50 Notes : "<<note50<<endl;
    // cout<<"Number of 20 Notes : "<<note20<<endl;
    // cout<<"Number of 1 Notes : "<<note1<<endl;

    //To calculate nCr:
    // int n,r;
    // cout<<"Enter the value of n and r:";
    // cin>>n>>r;
    // cout<<n<<"C"<<r<<" = "<<nCr(n,r)<<endl;

    //To calculate A.P Nth term 
    int num;
    cout<<"Enter value of n:";
    cin>>num;
    cout<<"Nth term : "<<AP(num)<<endl;

    //To count set bits of a and b
    int a,b;
    cout<<"Enter a and b:";
    cin>>a>>b;
    cout<<"Number of set bits in "<<a<<" and "<<b<<" are "<<countAandB(a,b)<<"."<<endl;

    //To print fibonacci series to nth term
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"The fibonacci series : ";
    fibonacci(n);



}