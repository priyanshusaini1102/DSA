#include <iostream>
#include <utility>
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

//🙋‍♂️ Binary Search ✅
int BinarySearch(int arr[],int size,int key){

    int start=0, end=size-1;

    int mid = start + (end-start)/2;

    while(start<=end){
        if(key == arr[mid]){
            return mid;
        }

        if(key < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    mid = start + (end-start)/2;

    return -1;

}

//🙋‍♂️ Ques-75(a) ✅ : To find leftmost key or first occurence in array
int firstOcc(int arr[], int size, int key){
    int start=0, end=size-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if(key == arr[mid]){
            ans = mid;
            end = mid-1;
        }else if(key < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    return ans;
}

//🙋‍♂️ Ques-75(b) ✅ : To find rightmost key or last occurence in array
int lastOcc(int arr[], int size, int key){
    int start=0, end=size-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if(key == arr[mid]){
            ans = mid;
            start = mid+1;
        }else if(key < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    return ans;
}

//🙋‍♂️ Ques-75 ✅ : To find first and last occurrence of a number.
// pair<int,int> findFirstAndLastOcc(int arr,int size,int num){
//     pair<int,int> pairIndex;
//     int first = firstOcc(arr,size,num);
//     int second = lastOcc(arr,size,num);
//     pairIndex.first = first;
//     pairIndex.second = second;
//     return pairIndex;
// }

//🙋‍♂️ Ques-76** ✅  : To find the peak index in a mountain array.
int getPeak(int arr[],int size){
    int start=0, end=size-1;
    int mid = start + (end-start)/2;

    while(start<end){
        if(arr[mid] < arr[mid+1]){
            start = mid+1;
        }else{
            end = mid;
        }

        mid = start+(end-start)/2;
    }
    return start;
}

//🙋‍♂️ Ques-77 ✅ : To find pivot in an array. Here, pivot is the value from which the sum to the left equals to the sum of right elements.
int pivotIndex(int arr[],int size){
    int leftSum=0, rightSum=0;
    for(int i=0;i<size;i++){
        rightSum = rightSum+arr[i];
    }

    for(int i=0; i<size;i++){
        if(i>0){
        leftSum = leftSum + arr[i-1];
        }
        rightSum = rightSum - arr[i];

        if(leftSum == rightSum){
            return i;
        }
    }

    return -1;
}



int main(){
    cout<<endl<<"~~~~~~~~START~~~~~~~~~~"<<endl<<endl;
    cout<<"Run successfully"<<endl;
    
    //input array
    int arr[1000] = {0};
    int size = getArr(arr);

    //input key
    // int key;
    // cout<<"Enter key to find: ";
    // cin>>key;
    
    //🙋‍♂️ Binary Search
    // int foundKey = BinarySearch(arr,size,key);
    // if(foundKey >= 0){
    //     cout<<key<<" is found at "<<foundKey<<" index."<<endl;
    // }else{
    //     cout<<key<<" is not found in the array."<<endl;
    // }

    //🙋‍♂️ Ques-75 : Find First and Last Occurrence in an array
    // pair<int,int> foundOcc = findFirstAndLastOcc(arr,size,key);
    
    //First Occurrence
    // int firstFoundKey = foundOcc.first;
    // if(firstFoundKey >= 0){
    //     cout<<"First occurrence of "<<key<<" is found at "<<firstFoundKey<<" index."<<endl;
    // }else{
    //     cout<<key<<" is not found in the array."<<endl;
    // }

    //Last Occurrence
    // int lastFoundKey = foundOcc.second;
    // if(lastFoundKey >= 0){
    //     cout<<"Last occurrence of "<<key<<" is found at "<<lastFoundKey<<" index."<<endl;
    // }else{
    //     cout<<key<<" is not found in the array."<<endl;
    // }

    //🙋‍♂️ Total No of Occurrence
    // int totalOccurrence = lastFoundKey-firstFoundKey+1;
    // if(totalOccurrence>=0){
    //     cout<<"Total Number of Occurrence of "<<key<<" is "<<totalOccurrence<<"."<<endl;
    // }else{
    //     cout<<key<<" is not found in the array."<<endl;
    // }

    //🙋‍♂️ Ques-76 : find peak index 
    // int peak = getPeak(arr,size);
    // cout<<"The peak index is "<<peak<<" and element is "<<arr[peak]<<"."<<endl;
    
    //🙋‍♂️ Ques-77 : to find pivot index 
    // int pivot = pivotIndex(arr,size);
    // if(pivot>=0){
    // cout<<"The pivot index is "<<pivot<<" and element "<<arr[pivot]<<"."<<endl;
    // }else{
    //     cout<<"The pivot index is not present in array."<<endl;
    // }

    
    


    cout<<endl<<endl<<"~~~~~~~~~~~~~~~END~~~~~~~~~~~~"<<endl;

}