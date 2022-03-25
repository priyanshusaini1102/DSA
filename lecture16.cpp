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
    for( int i=0; i<size; i++){
        for(int j=0; j<(size-i-1); j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

//🙋‍♂️Ques-87 ✅ : To Sort an array - Time Complexity : O(N^2)
void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main(){
    cout<<endl<<"~~~~~~~~START~~~~~~~~~~"<<endl<<endl;
    cout<<"Run successfully"<<endl;
    
    // Input array
    int arr[1000] = {0};
    int size = getArr(arr);

    selectionSort(arr,size);

    printArr(arr,size);

       
    cout<<endl<<endl<<"~~~~~~~~~~~~~~~END~~~~~~~~~~~~"<<endl;

}