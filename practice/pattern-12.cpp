#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cout<<"Enter a number : ";
    cin>>n;

    cout<<"\nPattern : \n";

    int i = 1;
    while(i<=n){
        //space

        int j = 1;
        while(j<=i-1){
            cout<<" ";
            j++;
        }

        //star
        int k = 1;
        while( k<= n-( i-1 )){
            cout<<"*";
            k++;
        }
        cout<<endl;
        i++;
    }

}