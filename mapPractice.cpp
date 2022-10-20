#include <iostream>
#include <map>

using namespace std;



int main(){

    map<int*,bool> m;
    int val = 5;
    int *ptr = &val; 
    m[ptr] = true;
    int val2 = 6;

    m[&val2] = true;

    int val3 = 7;

    for(auto i : m){
        cout<<*(i.first)<<" "<<i.second<<endl;
    }

    auto it = m.find(&val3);
    cout<<*(it->first)<<" "<<it->second<<endl;

    
}