#include <iostream>
#include <cmath>

using namespace std;

void printArr(int arr[], int n){
    cout<<"\n Array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int pow(int a, int b){
    int ans = 1;
    for(int i = 0; i <b; i++){
        ans = ans * a;
    }
    return ans;
}

void decimalToBinary(int n){
    int ans=0;
    int i=0;
    int numCpy = n;
    bool isNegative = false;
    if(n<0){
        isNegative = true;
        n = -1 * n;
    }
    // if(n<0){
    //     cout<<"Input must be positive."<<endl;
    // }
    int ansFinal = 0;
    while(n>0){
        if(n&1){
            ans = round(pow(10,i)) + ans;
        }
        i++;
        n = n>>1;
    }
    i=0;
    if(isNegative){
        while(ans>0){
            int lastDigit = ans%10;
            cout<<"lastDigit : "<<lastDigit<<endl;
            if(lastDigit == 0){
                ansFinal = pow(10,i)+ ansFinal;
            }
            i++;
            ans = ans/10;
        }
    }else{
        ansFinal = ans;
    }

    string msg = isNegative ? "Negative " : "";
    cout<<"Binary of "<<msg<<numCpy<<" is : "<<ans<<endl;
}

int bitwiseComplement(int n) {
        int mask = 0;
        int numCpy = n;
        if(n==0) return 1;
        while(n>0){
            mask = mask<<1;
            mask = (mask | 1);
            n = n>>1;
        }
        cout<<"mask : "<<mask<<endl;
        return (numCpy ^ mask);    
}

int binaryToDecimal(int n){
    int i=0;
    int ans = 0;
    while(n>0){
        int lastDigit = n%10;
        if(lastDigit == 1){
            ans = ans + pow(2,i);
        }
        i++;
        n = n/10;
    }

    return ans;
}

bool checkPowerOfTwo(int n){
    int count = 0;
    if(n == 0) return 0;
    while(n > 0){
        if(n&1){
            count++;
            if(count >1){
                return 0;
            }
        }
            n = n>>1;
    }
    return 1;
}

int calc(int a,int b, char op){
    switch(op){
        case '+':
            return (a+b);
            break;
        case '-':
            return (a-b);
            break;
        case '*':
            return (a*b);
            break;
        case '/':
            return (a/b);
            break;
        default : 
            cout<<"Enter valid operator "<<endl;
    }
}

void countNotes(int n){

    switch(1){
        case 1 : 
            cout<<"Number of notes of 100 : "<<n/100<<endl;
            n = n%100;
        case 2 : 
            cout<<"Number of notes of 50 : "<<n/50<<endl;
            n = n%50;
        case 3 : 
            cout<<"Number of notes of 20 : "<<n/20<<endl;
            n = n%20;
        case 4 : 
            cout<<"Number of coins of 1 : "<<n<<endl;
    }

}

int fact(int n){
    int ans = 1;
    int i=2;
    while(i<=n){
        ans = ans * i++;
    }
    return ans;
}

int nCr(int n, int r){
    int ans = 1;
    ans = fact(n) / (fact(r) * fact(n-r));
    // cout<<endl<<"Factorials are : "<<fact(n)<<" " <<fact(r)<<" " <<fact(n-r) <<endl;
    return ans;
}

void fibonacci(int n){
    int first = 0;
    int second = 1;
    int third = first + second;
    cout<< "\n 0 1";
    while(third <= n){
        cout<<" "<<third;
        first = second;
        second = third;
        third = first + second;
    }
}

void swapAdjacent(int arr[], int n){

    for(int i=1; i<n; i+=2){
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }

}

int uniqueElement(int arr[], int n){
    int ans = 0;
    for(int i=1; i<n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

long long threeWaySplit(int n, vector<int> arr){
    // Write your code here.
	long long s1=0,s3=0;
	long long ans = 0;
	
	int start = 0, end = arr.size()-1;
	s1+=arr[start];
	s3+=arr[end];
	while(start<end){
		if(s1 == s3){
			ans = s1;
			start++;
			end--;
		}
		if(s1>s3){
			end--;
			s3+=arr[end];
		}else{
			start++;
			s1+=arr[start];
		}
	}
	
	return ans;
}

int main(){
    // int n;
    // cout<<"Enter the value of n : ";
    // cin>>n;

    int arr[5] = {1,1,2,2,3};
    int uniqueEl = uniqueElement(arr,5);
    cout<<uniqueEl<<endl;
    // swapAdjacent(arr,5);
    // printArr(arr,5);

    // fibonacci(n);

    // int r;
    // cout<<"Enter the value of r : ";
    // cin>>r;
    // if(n>=r){
    //     cout<<n<<"C"<<r<<" : "<<nCr(n,r)<<endl;
    // }else{
    //     cout<<"N must be greater than r."<<endl;
    // }

    // countNotes(n);

    // int m;
    // char op;
    // cout<<"Enter expression : ";
    // cin>>n>>op>>m;
    // cout<<calc(n,m,op);

    // cout<<binaryToDecimal(n)<<endl;
    // decimalToBinary(n);
    // if(checkPowerOfTwo(n)){
    //     cout<<n<<" is the power of two."<<endl;
    // }else{
    //     cout<<n<<" is not the power of two."<<endl;
    // }

    // cout<<"bitwise compiliment : "<<bitwiseComplement(n)<<endl;

    // cout<<(-6 ^ 7)<<endl;
    // cout<<(~5)<<endl;
    // decimalToBinary(n);
    
    //To print this pattern
    // A 
    // B C
    // C D E
    // D E F G
    // E F G H I
    // 
    // for(int i = 0; i <n; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout<<(char)('A'+i+j)<<" ";      //typeid(x).name();
    //     }
    //     cout<<endl;
    // }

    //To print this pattern 
    // 0123454321
    // 0123**4321
    // 012****321
    // 01******21
    // 0********1
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(j<n-i)
    //             cout<<j;
    //         else{
    //             cout<<"*";
    //         }
    //     }
    //     for(int j=n; j>0; j--){
    //         if(j>n-i)
    //             cout<<"*";
    //         else{
    //             cout<<j;
    //         }
    //     }
    //     cout<<endl;
    // }

    //To print the reverse, sum and product of digits in a number.
    // int rev = 0;
    // int sum=0;
    // int product = 1;
    // while(n>0){
    //     int lastDigit = n%10;
    //     sum+=lastDigit;
    //     product*=lastDigit;
    //     rev = (rev*10) + lastDigit;
    //     n = n/10;
    // }
    // cout<<"reverse : "<<rev<<" product : "<<product<<" sum : "<<sum<<endl;

    //compiliment of base 10 number | input : 5 -> 101 | output : 2 -> 010 

}