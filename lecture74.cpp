#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Heap
{
private:
    int arr[100];
    int size;

public:
    Heap()
    {
        arr[0] = {0};
        size = 0;
    }

    //🙋‍♂to insert new element in heap
    void insert(int val)
    {
        arr[size + 1] = val;
        int i = size + 1;
        size++;
        while (i > 1)
        {
            if (arr[i / 2] > arr[i])
            { // change the comparison operator "> | <" accroding to min or max heap.
                swap(arr[i / 2], arr[i]);
                i = i / 2;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        arr[1] = arr[size];
        size--;

        int curr = 1;
        int left = curr * 2;
        int right = curr * 2 + 1;

        while (curr <= size)
        {

            if (left <= size && arr[left] < arr[curr])
            {
                swap(arr[left], arr[curr]);
                curr = left;
            }
            else if (right <= size && arr[right] < arr[curr])
            {
                swap(arr[right], arr[curr]);
                curr = right;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int size)
{
    int i = size/2;
    //1 based heap

    while (i > 0)
    {
        int curr = i;
        while (curr>0)
        {
            int left = 2 * curr;
            int right = 2 * curr + 1;
            int largest = curr;
            if(left<= size && arr[left]>arr[largest]){
                largest = left;
            }
            if(right<= size && arr[right]>arr[largest]){
                largest = right;
            }

            if(largest!=curr){
                swap(arr[largest],arr[curr]);
                curr = largest;
            }else{
                break;
            }
        }
        i--;
    }
}
//Heap sort for max heap
void heapSort(int arr[], int size) {
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        int curr = 1;
        while(curr>0){
            int left = 2 * curr;
            int right = 2 * curr + 1;
            int largest = curr;
            if(left<= size && arr[left]>arr[largest]){
                largest = left;
            }
            if(right<= size && arr[right]>arr[largest]){
                largest = right;
            }

            if(largest!=curr){
                swap(arr[largest],arr[curr]);
                curr = largest;
            }else{
                break;
            }
        }
        
    }
}

int main()
{

    int op;
    Heap h;
    h.insert(5);
    h.insert(4);
    h.insert(3);
    h.insert(2);
    h.insert(1);
    h.print();
    h.deleteFromHeap();
    h.print();

    cout<<"\nBefore heapify :";
    int arr[6] = {-1,1, 2, 3, 4, 5};
    for(int i = 1; i < 6;i++){
        cout<<arr[i]<<" ";
    }

    heapify(arr,5);
    cout<<"\nAfter heapify the array : ";
    for(int i = 0; i <= 5;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n after heap sort : ";
    heapSort(arr,5);
    for(int i = 0; i <= 5;i++){
        cout<<arr[i]<<" ";
    }


}