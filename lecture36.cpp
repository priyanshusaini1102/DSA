#include <iostream>
#include <vector>

using namespace std;

void getVector(vector<int>& arr){
    int n,val;
    cout<<"Enter the size of the array: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>val;
        arr.push_back(val);
    }
}

void printVector(vector<int> arr){
    int n = arr.size();
    cout<<"\nArray : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

//by love babbar
int partition( vector<int>& arr, int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void solve(vector<int>& arr, int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenfe
    int p = partition(arr, s, e);

    //left part sort karo
    solve(arr, s, p-1);

    //right wala part sort karo
    solve(arr, p+1, e);

}

//by me
//🙋‍♂️Ques-143 ✅ - Quick Sort
int partition(vector<int>& arr, int start, int end) {
    
    int pivot = arr[start];
    int count =0;
    for(int i=start+1;i<=end;i++) {
        if(arr[i] <= pivot){            //Here, arr[i] < pivot it also gives wrong answer (dont knw why but hopefully for make it stable) 💥
            count++;
        }
    }

    int pivotIndex = start+count;
    swap(arr[start],arr[pivotIndex]);
    int  i=start, j=end;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] <= pivot && i<pivotIndex) i++;

        while(arr[j] > pivot && j>pivotIndex) j--;

        if(i<pivotIndex && j>pivotIndex){           //check index ✔️ better than compare values like - arr[i] < pivot && arr[j] > pivot it gives TLE 💥 
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

    }

    return pivotIndex;

}

void solve(vector<int>& arr, int start, int end) {

    if(start >= end) return;

    int pivot = partition(arr, start, end);

    solve(arr, start,pivot-1);

    solve(arr, pivot+1,end);

}

int main(){

    vector<int> arr;
    getVector(arr);

    //🙋‍♂️Ques-143 ✅ - Merge Sort
    quickSort(arr,0,arr.size()-1);

    printVector(arr);

}