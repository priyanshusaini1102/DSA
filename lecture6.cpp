//Libraries
#include <iostream>
#include <math.h>
using namespace std;

//Functions
int reverse(int num){
    int ans=0;
    while(num!=0){
        int lastDigit = num%10;
        ans = (ans*10)+lastDigit;
        num/=10; 
    }

    return ans;
}
int sameOrder(int num){
    int ans=0;
    int i=0;
    while(num!=0){
        int lastDigit = num%10;
        ans = (lastDigit* round( pow(10,i) ))+ans;
        num/=10; 
        i++;
    }
    return ans;
}

//Main
int main(){
    //Heading
    cout<<endl<<"~~~~~~OUTPUT~~~~~~"<<endl<<endl;
    //Start
    
    //Decimal to Binary
    // {
    // int n, ans = 0, i=0;
    // cin >> n;
    // while(n!=0){
    //     int bit = (n&1);
    //     int pow10 = round(pow(10,i));
    //     ans = (bit * pow10)+ans;
    //     // cout<<"ans:"<<ans<<"bit:"<<bit<<"i:"<<i<<"pow10:"<<pow10 << endl;
    //     n = n >> 1;
    //     i++;
    // }
    //     cout << ans << endl;
    // }

    //Reverse and same order decimal number
    {
    int num =1230;
    int rev = reverse(num);
    int same = sameOrder(num);
    cout << "Reverse Order : " << rev << endl;
    cout << "Simple Order : " << same << endl;
    }
    

    //End
    cout<<endl;
}