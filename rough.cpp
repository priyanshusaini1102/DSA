#include <iostream>
#include <math.h>
#include <climits>

using namespace std;


int DecimalToBinary(int num){
    int ans = 0;
    int i = 0;
    while(num>0){
        // By Divide by 2 - it has an error in exceptional cases which have 0 in last or in most rightbit. 
        // {
        // int lastBit = num%2;
        // ans = (ans*10) + lastBit;
        // num = num/2;
        // }

        // By logical & operator with same order function with no exceptions working successfully.
        {
        int lastBit = num&1;
        ans = (lastBit * pow(10,i)) + ans;
        num = num >> 1;
        i++;
        }
    }

    return ans;
}

int BinaryToDecimal(int num){
    int ans =0, i=0;
    while(num>0){
        int lastBit = num%10;
        ans = (lastBit * pow(2,i)) + ans;
        num=num/10;
        i++;
    }

    return ans;
}

long long int NegativeDecimalToBinary(long long int n){
    long long int ans=0, i=0;
    if(n<0){
        n=pow(2,16)+n;
    }
    cout<<"n:"<<n<<endl;
    while(n){
        int lastBit = n&1;
        ans = (lastBit * round(pow(10,i))) + ans;
        n = n>>1;
        i++;
        cout<<ans<<endl;
    }
    cout << ans << endl;
    return ans;
}

bool rare(int num, int div){
    int lastDigit = num % 10;

    while(num >0){
        if(lastDigit % div != 0 ){
            return 0;
        }
        num/=10;
    }
    return 1;
}

void printPattern(int num){
    int k=1;
    while(k<=num){

        if(k == 1){
        cout<<"*";
        }

        if(k>1 && k<num){
            cout<<"*";
            for(int i=1;i<k;i++){
                cout<<"^";
            }
            cout<<"*";
        }

        if(k==num){
            for(int i=1; i<=num+1;i++){
                cout<<"*";
            }
        }

        cout<<endl;
        k++;
    }

}

int bitwiseComplement(int num){
    int numCopy = num;
    int mask=0;
    while(num){
        mask = mask << 1;
        mask = mask | 1;
        num = num >> 1;
    }
    cout<<"After Final iteration,\n";
    cout<<"Mask : "<<mask<<" and Num : "<<numCopy<<"."<<endl;
    // int ans = (mask ^ numCopy);
    int ans = (mask & ~numCopy);
    return ans;
}

bool powerOf2(int num){
    int setBitCount = 0;
    while(num){
        int lastBit = num & 1;
        if(lastBit == 1){
            setBitCount++;
        }
        if(setBitCount>1){
            return false;
        }
        num = num >> 1;
    }
    if(setBitCount == 1){
        return true;
    }

    return false;
}

bool efficientpowerOf2(int num){
    if(num <=0){
        return false;
    }
    return((num & (num-1)) == 0);
}

int main(){
    cout<<endl<<"~~~~~~~OUTPUT~~~~~~~~"<<endl<<endl;

    long long int num;
    cout<<"Enter a number: ";
    cin >> num;
    cout<<"Number - "<<num<<endl<<endl;

    //Decimal To Binary
    // int binary = DecimalToBinary(num);
    // cout<<"Binary of "<<num<<" is "<<binary<<"."<<endl;

    //Binary To Decimal
    // int decimal = BinaryToDecimal(num);
    // cout<<"Decimal of "<<num<<" is "<<decimal<<"."<<endl;

    //Logical not ~ but different from simple because most left bit print to be negative sign
    // int compliment = ~num;
    // cout<<"Compliment of "<<num<<" is "<<compliment<<"."<<endl; 

    //Negative Decimal to Binary
    // long long int negativeBinary = NegativeDecimalToBinary(num);
    // cout<<"Binary of "<<num<<" is "<<negativeBinary<<"."<<endl;

    //Check number is rare or not
    // cout<<"Enter value of div: ";
    // int div;
    // cin>>div;
    // bool isRare = rare(num,div);
    // if(isRare){
    //     cout<<"Yes, "<<num<<" is rare."<<endl;
    // }else{
    //     cout<<"No, "<<num<<" is not rare."<<endl;
    // }

    //printPattern
    // printPattern(num);

    //Bitwise XOR 
    // cout<<"XOR: "<<(num^num)<<endl;

    //Bitwise Complement
    // int ans = bitwiseComplement(num);
    // cout<< "Bitwise Complement of "<<num<<" : "<<ans<<"."<<endl;

    //powerOf2
    if(efficientpowerOf2(num)){
        cout<<"Yes, "<<num<<" is a power of 2."<<endl;
    }else{
        cout<<"No, "<<num<<" is not a power of 2."<<endl;
    }

    

    // cout<<"XOR:"<<(5^7)<<endl;

    cout<<endl<<"~~~~~~~~END~~~~~~~~~~"<<endl<<endl;
}