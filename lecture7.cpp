#include <iostream>

using namespace std;

int main(){
    int n = 5;
    int compliment = ~n;
    int bitForm = 0;
    while(n!=0){
        int lastBit = n&1;
        bitForm = lastBit;
        n = n >> 1;
    }
    cout << "BitForm : " << bitForm << endl;
     cout << "compliment" << (~5) << endl;
     cout << "Size of int : "<< sizeof(int)*8<<"bits."<<endl;
}