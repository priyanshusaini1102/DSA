#include <iostream>
#include <vector>

using namespace std;

void getVector(vector<int>& arr){
    int n,val;
    cout<<"\nEnter the size of array : ";
    cin>>n;
    cout<<"Enter "<<n<<" elements : ";
    for(int i=0; i<n; i++){
        cin>>val;
        arr.push_back(val);
    }

}

void printVector(vector<int> arr){
    int n = arr.size();
    // cout<<"\nSize of array in function : "<<n<<endl;
    cout<<"\nArray :";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void printArr(int arr[],int n){
    cout<<"Array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

//Call by value - it gives TLE ❌
vector<int> mergeTwoArray(vector<int> arr1, vector<int> arr2){

    int n1=arr1.size(),n2=arr2.size();
    vector<int> mergedArray;

    int i=0,j=0;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            mergedArray.push_back(arr1[i++]);
        }else{
            mergedArray.push_back(arr2[j++]);
        }
    }

    while(i<n1){
        mergedArray.push_back(arr1[i++]);
    }

    while(j<n2){
        mergedArray.push_back(arr2[j++]);
    }

    return mergedArray;
}

vector<int> merge(vector<int> arr, int start, int end) {

    // cout<<"\nstart: "<<start<<" end: "<<end<<endl;
    // printVector(arr);

    if(start == end) return arr;

    int mid = start + (end-start)/2;
    vector<int> left,right;
    int n1=mid+1, n2=end-mid;


    for(int i=start; i<=mid; i++) {
        left.push_back(arr[i]);
    }
    
    for(int j=mid+1; j<=end; j++) {
        right.push_back(arr[j]);
    }

    left = merge(left,0,n1-1);
    // cout<<"\nsize of left :"<<left.size()<<endl;
    // printVector(left);
    right = merge(right,0,n2-1);
    // cout<<"\nsize of right :"<<right.size()<<endl;
    // printVector(right);

    vector<int> ans = mergeTwoArray(left, right);
    // cout<<"\nSize of ans :"<<ans.size()<<endl;
    // printVector(ans);
    return ans;

}
 
//call by reference - it is not give TLE ✅
//🙋‍♂️Ques-142 ✅ - Merge Sort
void conquer(vector<int>& arr, int start, int end){
    int mid = start + (end-start)/2;

    int n1=mid-start+1,n2=end-mid;
    int k=start;
    int arr1[n1],arr2[n2];

    for(int i=0;i<n1;i++){
        arr1[i] = arr[k++];
    }

    for(int i=0;i<n2;i++){
        arr2[i] = arr[k++];
    }

    printArr(arr1,n1);
    printArr(arr2,n2);

    int i=0,j=0;
    k=start;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i++];
        }else{
            arr[k] = arr2[j++];
        }
        k++;
    }

    while(i<n1){
        arr[k] = arr1[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k] = arr2[j];
        k++;
        j++;
    }


}

void divide(vector<int>& arr, int start, int end) {
    if(start >= end) return;

    int mid = start + (end-start)/2;

    divide(arr, start, mid);

    divide(arr,mid+1,end);

    conquer(arr,start,end);
}

int main(){
    
    vector<int> arr;
    getVector(arr);

    //vector<int> mergedArray = merge(arr,0,arr.size()-1);          //GIVES TLE ❌
    //🙋‍♂️Ques-142 ✅ - Merge Sort
    divide(arr,0,arr.size()-1);                                     //NOT GIEVS TLE ✅
    printVector(arr);

}