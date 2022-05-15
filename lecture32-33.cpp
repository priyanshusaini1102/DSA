#include <iostream>

using namespace std;
//🙋‍♂️Ques-116 ✅ : reach destination to n  using recursion.
void reachDestinaton(int src, int dest){
    cout<<src<<" reached and remaining "<<dest-src<<" more to reach."<<endl;
    if(src >= dest){
        cout<<"Reached Destination!"<<endl;
        return;
    }

    return reachDestinaton(++src, dest);
}

//🙋‍♂️Ques-117 ✅ : calculate N th term of fibonacci series.
int fibonacci(int n ){
    if(n==0) return 0;
    if(n==1) return 1;

    return (fibonacci(n-1)+fibonacci(n-2));
}

//🙋‍♂️Ques-118 ✅ : count the total number of ways to reach N th stair. 
int stairDistinctWays(int n){
    if(n == 0) return 1;

    if(n == 1) return 1;

    if(n == 2) return 2;

    return (stairDistinctWays(n-1) + stairDistinctWays(n-2));

}

//🙋‍♂️Ques-119 ✅ : print digits in alphabets in same order.
void printInAlphabets(int n, string arr[]){

    if(n == 0){
        return;
    }

    int digit = n%10;
    n = n/10;

    printInAlphabets(n,arr);
    cout<<arr[digit]<<" ";
}

//~~~~~~~~~~~~lecture-32 complete~~~~~~~~~~~~~~~

//🙋‍♂️Ques-120 ✅ : to check the given array is sorted or not.
bool isSorted(int *arr, int size){

    //BASE conditions
    if(size == 1 || size==0) return true;

    if(arr[0]>arr[1]) return false;

    return isSorted(arr+1, size-1);

}
//🙋‍♂️Ques-121 ✅ : to calculate the total sum of all the elements in the array.
int getSum(int *arr, int size){
    //base case
    if(size==1) return arr[0];

    // iteration call
    return arr[0]+getSum(arr+1, size-1);
}
//🙋‍♂️Ques-122 ✅ : linear search in array using recursion.
bool linearSearch(int *arr, int size, int key){
    
    if(size == 0) return false;

    if(arr[0] == key) return true;

    return linearSearch(arr+1, size-1,key);
}

// lecture 12-15 question using recursion. - lecture33revision.cpp

int main(){

    // int source,destination;
    // cout<<"Enter the value of source and destination : ";
    // cin>>source>>destination;  
    // reachDestinaton(source,destination);

    // int n;
    // cout<<"Enter the value of n : ";
    // cin>>n;
    // cout<<"The number of distinct ways to reach the nth stair : "<<stairDistinctWays(n)<<endl;

    // int n;
    // cout<<"Enter value of n : ";
    // cin>>n;
    // string arr[10] = {"ZERO","ONE", "TWO", "THREE", "FOUR", "FIVE","SIX", "SEVEN", "EIGHT", "NINE"};
    // // cout<<arr[3]<<endl;
    // printInAlphabets(n, arr);

    // int arr[3] = {4,40,4};
    // string result = isSorted(arr,3) ? "is sorted" : "is not sorted";
    // cout<<result<<endl;

    // cout<<"Total sum of element is "<<getSum(arr,3)<<endl;

    // int key;
    // cout<<"key: ";cin>>key;
    // string result = linearSearch(arr,3,key) ? " present" : " not present";
    // cout<<result<<endl;

    // int n=5;
    // for(int i=0; i<=n; i++){
    //     cout<<fibonacci(i)<<" ";
    // }



}