#include <iostream>
#include <vector>

using namespace std;

int fastPower(int x,int n){
    int res = 1;
    while(n>0){
        if(n&1){
            //if b is odd
            res = res * x;
        }
        x = x*x;
        n = n>>1;

        return res;
    }
}

bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}


//🙋‍♂️Ques-111 ✅ : Sieve of Eratosthenes
int countPrimes(int n){

    int count = 0;

    vector<bool> primes(n+1, true);

    primes[0] = primes[1] = false;

    for(int i=2; i<n; i++){
        if(primes[i]){
            int j=2;
            while(j*i < n){
                primes[j*i] = false;
                j++;
            }
            count++;
        }

    }

}

//🙋‍♂️Ques-112 ✅ : Euclid's algorithm
int gcd(int a, int b){
    if(a==0){
        return b;
    }

    if(b == 0){
        return a;
    }

    while(a!=b){
        if(a>b){
            a = a-b;
        }else{
            b = b-a;
        }
    }

    return a;
}

int main(){

    int a,b;
    cout<<"Enter the value of a and b to find gcd(a,b) : ";
    cin>>a>>b;
    cout<<"gcd("<<a<<","<<b<<") : "<<gcd(a,b)<<endl;

}