#include <iostream>

using namespace std;

void reachDestinaton(int src, int dest){
    cout<<src<<" reached and remaining "<<dest-src<<" more to reach."<<endl;
    if(src >= dest){
        cout<<"Reached Destination!"<<endl;
        return;
    }

    return reachDestinaton(++src, dest);
}

int stairDistinctWays(int n){
    if(n == 0) return 1;

    if(n == 1) return 1;

    if(n == 2) return 2;

    return (stairDistinctWays(n-1) + stairDistinctWays(n-2));

}

void printInAlphabets(int n, string arr[]){

    if(n == 0){
        return;
    }

    int digit = n%10;
    n = n/10;

    printInAlphabets(n,arr);
    cout<<arr[digit]<<" ";
}

bool isSorted(int *arr, int size){

    //BASE conditions
    if(size == 1 || size==0) return true;

    if(arr[0]>arr[1]) return false;

    return isSorted(arr+1, size-1);

}

int getSum(int *arr, int size){
    //base case
    if(size==1) return arr[0];

    // iteration call
    return arr[0]+getSum(arr+1, size-1);
}

bool linearSearch(int *arr, int size, int key){
    
    if(size == 0) return false;

    if(arr[0] == key) return true;

    return linearSearch(arr+1, size-1,key);
}

int fibonacci(int n ){
    if(n==0) return 0;
    if(n==1) return 1;

    return (fibonacci(n-1)+fibonacci(n-2));
}

int binarySearch(int start, int end, int arr[], int key){
    int mid = start + (end-start)/2;

    if(start>end) return -1;

    if(key == arr[mid]) return mid;

    if(arr[mid] < key){
        return binarySearch(mid+1, end, arr,key);
    }else{
        return binarySearch(start, mid-1, arr,key);
    }

}

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

    // int arr[3] = {1,11,111};
    // int size = 3;
    // int key;
    // cout<<"Enter the value of key : ";cin>>key;

    // int foundAt = binarySearch(0,size-1, arr,key);
    
    // if(foundAt == -1){
    //     cout<<key<<" is not found in the array."<<endl;
    // }else{
    //     cout<<key<<" is found in the array at "<<foundAt<<endl;
    // }


}