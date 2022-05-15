#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    cout<<"\nArray : ";
    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }
}

void scanArray(int *arr, int& n){
    cout<<"enter the size of the array :";
    cin>>n;

    cout<<"Enter "<<n<<" element : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

//Find first occurrence of element using binary search recursion.
int firstOccurrence(int start, int end,int *arr, int key,int ans = -1){
    
    if(start > end){
        return ans;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == key){
        ans = mid;
        firstOccurrence(start, mid-1, arr, key,ans);
    }else if(arr[mid] > key){
        firstOccurrence(start, mid-1, arr, key,ans);
    }else{
        firstOccurrence(mid+1, end, arr, key,ans);
    }
    
}

//Find last occurrence of element using binary search recursion.
int lastOccurrence(int start, int end, int arr[], int key, int ans = -1){

    if(start > end){
        return ans;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == key){
        ans = mid;
        lastOccurrence(mid+1, end, arr, key, ans);
    }else if(arr[mid] > key){
        lastOccurrence(start, mid-1, arr, key,ans);
    }else{
        lastOccurrence(mid+1,end, arr, key, ans);
    }

}

//To check the difference between binary search using loop and recursion.
int firstOccurrenceWithLoop(int arr[], int n, int key){

    int start = 0, end = n-1, ans = -1;
    int mid = start + (end-start)/2;
    cout<<"\n0.start : "<<start<<" | end : "<<end<<" | ans : "<<ans;

    while(start<=end){
        if(arr[mid] == key){
            ans = mid;
            end = mid-1;
            cout<<"\n1.start : "<<start<<" | end : "<<end<<" | ans : "<<ans;
        }else if(arr[mid] > key){                                                    //🕊️else if important
            cout<<"\n2.start : "<<start<<" | end : "<<end<<" | ans : "<<ans;
            end = mid-1;
        }else{
            cout<<"\n3.start : "<<start<<" | end : "<<end<<" | ans : "<<ans;
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;

}

//Using Recursion ✅
int peakIndexOfMountain(int start, int end, int arr[]){
    
    if(start == end){
        return start; 
    }

    int mid = start + (end-start)/2;

    if(arr[mid] < arr[mid+1]){
        peakIndexOfMountain(mid+1, end, arr);
    }else{
        peakIndexOfMountain(start, mid, arr);
    }
}

//to find pivot(minimum element) index in sorted and rotated array. ✅
int pivotIndex(int start, int end, int arr[], int ans=-1){

    //base case
    if(start >= end) return start;

    //processing
    int mid = start + (end-start)/2;

    //recursion call
    if(arr[mid] < arr[0]){ 
        ans = mid;
        pivotIndex(start, mid, arr, ans);
    }else{
        pivotIndex(mid+1, end, arr, ans);
    }

}

int sqrt(int key){
    int start=0, end=key;
    int mid=start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if(mid*mid <= key){
            ans = mid;
            start = mid + 1;
        }

        if(mid*mid < key){
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

double sqrtWithPrecision(int key, int precision){
    double ans = sqrt(key);
    double factor = 1;
    for(int i = 0; i <precision; i++){
        factor = factor/10;
    }
    double preciseAns = ans;
    double i =0;
    double precise = 0;
    while(i<1){
        precise = ans + i;

        if(precise*precise <= key){
            preciseAns = precise;
        }else{
            break;
        }
        i+=factor;
    }
    return preciseAns;
}

bool isPossibleAllocation(int arr[], int n,int s, int mid){
    int student = 1;
    int sum = 0;
    for(int i = 0; i<n; i++){
        // if(arr[i]>mid) return false;
        if((sum+arr[i])<=mid){
            sum+=arr[i];
        }else{
            student++;
            sum=arr[i];
            if(arr[i] > mid || student > s) return false;
        }
    }
    cout<<"\n student:"<<student<<"\t mid:"<<mid<<endl;

    return true;
}

int bookAllocate(int arr[], int n, int m, int start, int end, int ans = -1){
    if(start > end) return ans;

    int mid = start + (end-start)/2;

    if(isPossibleAllocation(arr,n,m,mid)){
        ans = mid;
        bookAllocate(arr,n,m,start,mid-1,ans);
    }else{
        bookAllocate(arr,n,m,mid+1,end,ans);
    }
}

int main(){

    int arr[1000],n;
    scanArray(arr,n);
    printArray(arr, n);

    int m;
    cout<<"\nEnter the number of students : ";
    cin>>m;

    int sum=0;
    for(int i=0;i<n; i++){
        sum+=arr[i];
    }
    int ans = bookAllocate(arr,n,m,0,sum);
    cout<<"\nans: "<<ans<<endl;

    // cout<<"Enter the value of n :";
    // cin>>n;
    // cout<<"\nSquare root of "<<n<<" is : "<<sqrtWithPrecision(n,2)<<endl;

    // int key;
    // cout<<"\nEnter key: ";
    // cin>>key;

    // cout<<"\nFirst Occurrence : "<<firstOccurrence(0,3,arr, key);
    // cout<<"\nLast Occurrence : "<<lastOccurrence(0,3,arr, key);

    // cout<<"\nPeak Index of Mountain Array : "<<peakIndexOfMountain(0,n-1,arr);

    // cout<<(0 > -1); 

    // int pivIndex = pivotIndex(0,n-1, arr);
    // cout<<"\n pivot index :"<<pivIndex<<" arr["<<pivIndex<<"] : "<<arr[pivIndex];

}