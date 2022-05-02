#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    bool lowerCase=false, upperCase=false, number=false, specialCh=false;
    bool luns[4] = {0};
    int remLength = (6-n)>0 ? (6-n) : 0;
    for(int i=0;i<n; i++){
        char ch = password[i];
        if(ch>= 'a' && ch<='z'){
            luns[0] = true;
        }else if(ch>='A' && ch<='Z'){
            luns[1] = true;
        }else if(ch == 33 || (ch>=35 && ch<=38) || (ch>=40 && ch<=43) || ch==45 || ch==64 || ch==94){       //to check special characters instead of this we can check this by using fir loop in a string 
            luns[3] = true;
        }else if(ch>='0' && ch<='9'){
            luns[2] = true;
        }
    }
    int count = 0;
    for(int i=0; i<4; i++){
        if(luns[i] == false){
           count++; 
        }
    }
    cout<<"count : "<<count<<endl;
    cout<<"remLength : "<<remLength<<endl;

    int difference = (count-remLength)>=0 ? (remLength-count) : 0; 
    cout<<"difference : "<<difference<<endl;
    int ans = remLength+difference;
    return ans;
}

int main(){
    string password = "#HackerRank";
    int n = 11;

    cout<<minimumNumber(n, password);
}
