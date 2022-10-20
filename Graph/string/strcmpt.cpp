#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool comp(string a,string b){
    return a>b;
}

int main(){
    

    vector<string> v = {"97","98"};
    sort(v.begin(), v.end(),comp);
    for(string i:v){
        cout<<i<<" ";
    }


}