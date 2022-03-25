#include <iostream>

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

//To Sort an array - Time Complexity : O(N^2)
void bubbleSort(int a[],int size){
    for( int i=1; i<size; i++){
        bool isSwap = false;
        for(int j=0; j<(size-i); j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                isSwap = true;
            }
        }
        if(isSwap == false){
            break;
        }
    }
}

//🙋‍♂️Ques-89 ✅ : To sort an array - Time Complexity : O(N^2)
void insertionSort(int arr[], int size){
    
    for(int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j >= 0; j--) {
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;

    }

}

int main(){
    cout<<endl<<"~~~~~~~~START~~~~~~~~~~"<<endl<<endl;
    cout<<"Run successfully"<<endl;
    
    // Input array
    int arr[1000] = {0};
    int size = getArr(arr);

    insertionSort(arr,size);

    printArr(arr,size);



    cout<<endl<<endl<<"~~~~~~~~~END~~~~~~~~~~~"<<endl;

}