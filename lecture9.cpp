#include<iostream>
#include<climits>

using namespace std;

void printArray(int arr[],int size){
    cout<<"Array : [";
    for(int i=0;i<size;i++){
        cout<<" "<<arr[i];
    }
    cout<<" ]"<<endl;
}


int getMax(int num[], int size){
    int max = num[0];

    for(int i=0;i<size;i++){
        if(num[i] > max){
            max =num[i];
        }
    }

    return max;
}
int getMin(int num[], int size){
    int min = num[0];

    for(int i=0;i<size;i++){
        if(num[i] < min){
            min =num[i];
        }
    }

    return min;
}
int getSum(int num[], int size){
    int sum = 0, i = 0;
    while(i<size){
        sum+=num[i];
        i++;
    }
    return sum;
}
void revArray(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

bool linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(key == arr[i]){
            return 1;
        }
    }
    return 0;
}

void swapAlternate(int arr[], int size){
    // 1 2 3 4 5
    for(int i=1;i<size;i=i+2){
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }
}

int findUnique(int arr[], int size){
    int ans=0;
    for(int i=0; i<size; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

//Unique Number Of Occurence - Leetcode:1207
bool uniqueNoOfOccurence(int arr[], int size){
    bool isCounted[100] = {0};
    int countArr[100] = {0};
    int countArrayIndex = 0;
    for(int i=0; i<size; i++){
        if(isCounted[i]){
            continue;
        }
        int count = 1;
        for(int j=i+1; j<size; j++){
            if(isCounted[j]){
                continue;
            }
            if(arr[i] == arr[j]){
                count++;
                isCounted[j] = 1;
            }
        }
        countArr[countArrayIndex] = count;
        countArrayIndex++;
        isCounted[i] = 1;
    }

    for(int i=0; i<countArrayIndex; i++){
        int check = countArr[i];
        int count=0;
        for(int j=i+1;j<countArrayIndex;j++){
            if(check == countArr[j]){
                return 0;
            }
        }
    }
        return 1;
}

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

//Unique Number Of Occurence Optimised - Leetcode:1207
bool OPuniqueNoOfOccurrence(int arr[], int size){
    bubbleSort(arr,size);

    int ans[100] = {0};
    int ansCounter = 0;
    
    int count = 0;
    
    for(int i=0; i<size;i++){
        if(i<size-1 && arr[i]==arr[i+1]){
            count++;
        }else{
            ans[ansCounter] = count+1;
            ansCounter++;
            count=0;
        }
    }

    bubbleSort(ans,ansCounter);

    for(int i=1; i<ansCounter; i++){
        if(ans[i] == ans[i-1]){
            return 0;
        }
    }
    return 1;
}

//Find Duplicate element in array [1,N-1,duplicate element]
int findDuplicate(int arr[], int size){
    
    int ans = 0;
    for(int i=0; i<size; i++){
        ans = (ans ^ arr[i]);
    }

    for(int i=1; i<size;i++){
        ans = (ans ^ i);
    }
    return ans;
}


//return all duplicate element in form of array - LeetCode:442
void findAllDuplicate(int arr[], int size){
    int ans[100] = {0};
    int ansCounter = 0;

    bubbleSort(arr,size);

    for(int i=0; i<size-1; i++){
        if(arr[i] == arr[i+1]){
            ans[ansCounter] = arr[i];
            ansCounter++;
            i++; //skip next term also because it saved in ans[]
        }
    }
    
    printArray(ans,ansCounter);
}

//To Print Intersection of two arrays
void intersection(int arr1[],int n,int arr2[], int m){
    int i=0;
    int j=0;
    int ans[100] = {0};
    int ansCounter = 0;
    while (i<n && j<m)
    {
        if(arr1[i] < arr2[j]){
            i++;
        }
        if(arr1[i] == arr2[j]){
            ans[ansCounter]=arr1[i];
            ansCounter++;
            arr2[j] = -1;
            i++;
            j++;
        }
        if(arr1[i] > arr2[j]){
            j++;
        }
    }

    printArray(ans,ansCounter);
    
}

//To print array of Pair Sum
void pairSum(int arr[], int size, int sum){
    int ans[100] = {0};
    int ansCounter = 0;

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]+arr[j] == sum){
                ans[ansCounter] = arr[i];
                ans[ansCounter+1] = arr[j];
                ansCounter+=2;
            }
        }
    }

    printArray(ans,ansCounter);
}

void OPpairSum(int arr[], int size, int targetSum){
    int ans[100] = {0};
    int ansCounter = 0;

    bubbleSort(arr,size);

    int i=0,j=size-1;
    while(i<j && j<size){
        int sum = arr[i] + arr[j];
        if(sum == targetSum){
            ans[ansCounter] = arr[i];
            ans[ansCounter+1] = arr[j];
            ansCounter+=2;
            i++;
            j--;
        }
        if(sum<targetSum){
            i++;
        }
        if(sum>targetSum){
            j--;
        }
    }

    printArray(ans,ansCounter);
}

//triplet sum
void tripletSum(int arr[], int size, int sum){
    int ans[100] = {0};
    int ansCounter = 0;

    bubbleSort(arr,size);

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                if(arr[i]+arr[j]+arr[k] == sum){
                    ans[ansCounter] = arr[i];
                    ans[ansCounter+1] = arr[j];
                    ans[ansCounter+2] = arr[k];
                    ansCounter+=3;
                }
            }
        }
    }

    printArray(ans,ansCounter);
}

//Optimised Triplet sum
void OPtripletSum(int arr[], int size, int target){
    int ans[100] = {0};
    int ansCounter = 0;
    bubbleSort(arr,size);

    for(int i=0;i<size-2;i++){
        if(i>0 && arr[i] == arr[i-1]){
            continue;
        }
        int l = i+1, r = size-1;

        while (l < r)
        {
            int sum = arr[i]+arr[l]+arr[r];
            if(sum == target){
                ans[ansCounter] = arr[i];
                ans[ansCounter+1] = arr[l];
                ans[ansCounter+2] = arr[r];
                ansCounter+=3;
            cout<<i<<":"<<arr[i]<<" "<<arr[l]<< " "<<arr[r]<<endl;
                l++;
                r--;
                while(arr[l] == arr[l-1]){
                    l++;
                }
                while(arr[r] == arr[r+1]){
                    r--;
                }
                
            }
            
            if(sum < target){
                l++;
                while(arr[l] == arr[l-1]){
                    l++;
                }
            }
            if(sum > target){
                r--;
                while(arr[r] == arr[r+1]){
                    r--;
                }
            }
        }
    }

    printArray(ans,ansCounter);
}
//Pending 
//sort(0,1,2) like sort(0,1)

void sort012(int arr[], int size){
    int i=0;
    int l = i;
    int r = (size-1);

    while(l<=r){
        while(arr[i]==0 && i<size-1){
            i++;
            if(l<i){
            l=i;   
            }
        }
        while(arr[l] == 1 ){
            l++;
        }
        while(arr[r] == 2){
            r--;
        }
        if((l==r && i==l) || (l>r)){
            break;
        }
        
        if(arr[l]==0){
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
            i++;
            if(l<i){
            l=i;   
            }
        }
        if(arr[r]==0){
            int temp = arr[r];
            arr[r] = arr[i];
            arr[i] = temp;
            i++;
            if(l<i){
            l=i;   
            }
        }
        if(arr[l] == 2 && arr[r] == 1 && l<r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
}

void OPsort012(int arr[], int size){
    int i = 0, j = 0, k = size - 1;
    while (i <= k) {
      if (arr[i] == 0) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j++;
      } else if (arr[i] == 1) {
        i++;
      } else {
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        k--;
      }
    }
}

//Sort (0,1)
void sort0and1(int arr[], int size){
    int i=0,j=size-1;

    while(i<j){
        if(arr[i]==1 && arr[j]==0){
            swap(arr[i],arr[j]);
        }
        while(arr[i]==0){
            i++;
        }
        while(arr[j]==1){
            j--;
        }
    }
}

int inputArray(int arr[]){
    int size;
    cout <<"Enter the size of array : ";
    cin >> size;
    cout<<"Enter "<<size<<" values: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    return size;
}

int main(){
    cout<<endl<<"~~~~~START~~~~~"<<endl<<endl;

    //to initialize all elements with same value
    // int arr[5]={0};
    // int num;
    // cout<<"Enter the number: ";
    // cin>>num;
    // for(int i=0;i<5;i++){
    //     arr[i] = num;
    // }
    // printArray(arr,5);

    int arr[100];
    int size = inputArray(arr);

    //Sort(0,1)
    // sort0and1(arr,size);
    // cout<<"After Sorting...\n";
    // printArray(arr,size);

    //Sort(0,1,2)
    OPsort012(arr,size);
    printArray(arr,size);

    // Input for Pair Sum & Triplet Sum
    // int sum;
    // cout<<"Enter the value of sum : ";
    // cin>>sum;

    //Pair sum
    // pairSum(arr,size,sum);

    //Pair Sum Optimised
    // OPpairSum(arr,size,sum);

    //Triplet sum
    // tripletSum(arr,size,sum);

    //Optimised Triplet sum
    // OPtripletSum(arr,size,sum);

    // int brr[100];
    // int size2 = inputArray(brr);
    // intersection(arr,size,brr,size2);

    //Find all duplicate terms
    // findAllDuplicate(arr,size);

    //Find Duplicate element range [1, N-1] with duplicate element
    // int duplicateElement = findDuplicate(arr,size);
    // cout<<"Duplicate element : "<<duplicateElement<<endl;

    // Unique Number Of Occurrence
    // if(uniqueNoOfOccurence(arr,size)){
    //     cout<<"Yes"<<endl;
    // }else{
    //     cout<<"No"<<endl;
    // }

    //Swap Adjacent elements in array
    // swapAlternate(arr,size);
    // cout<<"After swapping:\n";
    // printArray(arr,size);

    //Find unique element in array using xor(^) | size is always odd(size=2m+1)
    // int uniqueElement = findUnique(arr,size);
    // cout<<"Unique element in array : "<<uniqueElement<<endl;

    //Linear Search
    // int key;
    // cout<<"Enter the element to find in array : ";
    // cin>>key;
    // if(linearSearch(arr,size,key)){
    //     cout<<"Yes, "<<key<<" is present in array."<<endl;
    // }else{
    //     cout<<"No, "<<key<<" is not present in array."<<endl;
    // }

    // Reverse array
    // revArray(arr, size);
    // cout<<"After reverse : "<<endl;
    // printArray(arr,size); 

    // To find minimum and maximum value in an array
    // cout << "Max value : " << getMax(arr,size) << endl;
    // cout << "Min value : " << getMin(arr,size) << endl; 
    
    //To find sum of all elements in an array
    // cout<<"Sum of array elements is "<<getSum(arr,size)<<"."<<endl;

    

    cout<<endl<<"~~~~~~END~~~~~~"<<endl<<endl;
    

}