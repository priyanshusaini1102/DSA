#include <iostream>

using namespace std;

//๐โโ๏ธQues-113 โ : print count to N using recursion.
void printCount(int n){
    //Base Case
    if(n==0){
        cout<<n<<" "<<endl;
        return;
    }

    printCount(n-1);
    cout<<n<<" "<<endl;
}

//๐โโ๏ธQues-114 โ : calculate factorial using recursion.
int fact(int n ){
    if(n==1){
        return 1;
    }
    return n * fact(n-1);
}

//๐โโ๏ธQues-115 โ : calculate power of a^b using recursion.
int power(int a, int b){
    if(b == 1){

        return a;
    }
    return a * power(a, b-1);
    // cout<<a*fact(b-1)<<endl;
}

int main(){

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    //๐โโ๏ธQues-113 โ : print count to N using recursion.
    printCount(n);

    //๐โโ๏ธQues-114 โ : calculate factorial using recursion.
    int factAns = fact(n);
    cout<<"factorial of "<<n<<" = "<<factAns<<endl;

    //๐โโ๏ธQues-115 โ : calculate power of a^b using recursion.
    int powerOf2 = power(2,n);
    cout<<"Power of 2 = "<<powerOf2<<endl;

}