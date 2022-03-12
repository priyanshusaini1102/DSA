#include<iostream>

using namespace std;


//To input an array
int getArr(int arr[]){
    int size;
    cout<<"Enter the size of Array: ";
    cin>>size;

    cout<<"Enter the elements : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    return size;
}

//To print an array
void printArr(int arr[], int size){
    cout<<"Array : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"."<<endl;
}

//Binary Search -> O(n)
int BinarySearch(int arr[],int start,int end, int key){
    
    int mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }

        if(arr[mid] > key){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

//🙋‍♂️ Ques-78 ✅ : To find pivot in an sorted and rotated array.i.e., [1,2,3,4,5] -> [4,5,1,2,3]
//Here, Pivot element is 1.(minimum value). -> O(n)
int pivotInSortedandRotatedArr(int arr[], int size){
    int start=0, end=size-1;
    int mid = start + (end-start)/2;

    while(start<end){
        if(arr[mid] > arr[0]){
            start = mid+1;
        }else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }

    return start;   //End == start, so return any one from these.
}

//🙋‍♂️ Ques-79 ✅ : To find a key in sorted and rotated array. -> O(n)
int findKeyInSortedAndRotatedArr(int arr[],int size, int key){
    int start=0,end=size-1;
    int mid = start + (end-start)/2;

    int pivot = pivotInSortedandRotatedArr(arr,size);
    if(key >= pivot && key <= arr[end]){
        return BinarySearch(arr,pivot,end,key);
    }else{
        return BinarySearch(arr,start,pivot-1,key);
    }
    
}

//🙋‍♂️Ques-80 ✅ : To find Square Root of a number using Binary Search without precision.i.e.,3.023
int sqrt(int key){
    int start=0,end=key;
    long long int mid = start + (end-start)/2;
    long long int ans = -1;
    while(start <= end){
        if(mid*mid == key){     //we take long long int bcoz mid*mid may be greater than INT_MAX.
            return mid;
        }

        if(mid*mid > key){
            end = mid-1;
        }else{
            start = mid+1;
            ans = mid;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

//🙋‍♂️Ques-80+ ✅ : To find Square root with precision using binary search.
double sqrtWithPrecision(int key,int precision){
    double ans = sqrt(key);
    double factor = 1;
    for(int i=0;i<precision;i++){
        factor = factor/10;
    }

    for(double i=ans;i<ans+1;i = i+factor){
        if(i*i <= key ){
            ans = i;
        }else{
            break;
        }
    }
    return ans;
}

int main(){
    cout<<endl<<"~~~~~~~~START~~~~~~~~~~"<<endl<<endl;
    cout<<"Run successfully"<<endl;
    
    //input array
    int arr[1000] = {0};
    int size = getArr(arr);

    //input key
    int key;
    cout<<"Enter key to find: ";
    cin>>key;

    //input precision for sqrt question.
    int precision;
    cout<<"Enter precision : ";
    cin>>precision;

    //🙋‍♂️ Ques-78 : To find pivot in an sorted and rotated array.
    // int pivot = pivotInSortedandRotatedArr(arr,size);
    // cout<<"The pivot index : "<<pivot<<" and arr["<<pivot<<"] : "<<arr[pivot]<<endl;

    //🙋‍♂️ Ques-79 : To find a key in sorted and rotated array.
    // int foundIndex = findKeyInSortedAndRotatedArr(arr,size,key);
    // if(foundIndex >=0){
    //     cout<<"The pivot index : "<<foundIndex<<" and arr["<<foundIndex<<"] : "<<arr[foundIndex]<<endl;
    // }else{
    //     cout<<key<<" is not found in array."<<endl;
    // }

    //🙋‍♂️Ques-80 : To find Sqaure root of given key using binary search;
    // int ans = sqrt(key);
    // cout<<"Answer : "<<ans<<endl;

    //🙋‍♂️Ques-80+ : To find Sqaure root of given key using binary search with precision.
    double ans = sqrtWithPrecision(key,precision);
    cout<<"Answer : "<<ans<<endl;

    cout<<endl<<endl<<"~~~~~~~~~~~~~~~END~~~~~~~~~~~~"<<endl;

    
}