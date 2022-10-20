#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> track(26,0);

    string str;
    cin>>str;

    for(int i=0;i<str.size();i++){
        if(str[i]==str[i-1]){

            if(track[c-'a']<2){
                cout<<c;
                track[c-'a']++;
            }
            
        }
    }

}