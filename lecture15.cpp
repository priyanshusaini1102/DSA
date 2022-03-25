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


bool isPossible(int arr[],int size,int m, int mid){
    int student = 1;
    int sum = 0;

    for(int i=0; i<size; i++){
        if(sum+arr[i] <= mid){
            sum+=arr[i];
        }else{
            student++;
            sum = arr[i];

            if(arr[i] > mid || student > m){
                return false;
            }

        }
    }

    return true;
}

bool isPossibleCows(int arr[],int size, int c, int mid){
    int cow = 0;
    int cowNumber = 1;

    for(int i=0; i<size; i++){
        if(arr[i] - arr[cow] >= mid ){
            cow = i;
            cowNumber++;
            if(cowNumber == c){
                return true;
            }
        }
    }
    return false;
}

bool isPossibleHeight(int arr[], int size, int m, int mid){
    int totalWood = 0;
    for(int i=0; i<size; i++){
        if(arr[i] > mid){
        int wood = arr[i]-mid;
        totalWood += wood;
        }
    }

    if(totalWood >= m){
        return true;
    }else{
        return false;
    }
}

bool isPossibleTime(int arr[], int size, int p, int mid){
    int time =0 ;
    int prataDone = 0;

    for(int i=0; i<size; i++){
        time = arr[i];
        int j = 2;
        while(time<=mid){
            prataDone++;
            if(prataDone>=p){
            return 1;
            }
            time = time + (arr[i] * j);
            j++; 
        }   
    }
    return 0;
}

int binarySearchForTriplets(int arr[],int i, int start, int end, int d){
    int mid = start + (end-start)/2;

    while(start <= end){
        if(arr[mid]-arr[i] < d){
            start = mid+1;
        }else if(arr[mid]-arr[i] > d){
            end = mid-1;
        }else{
            return mid;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}


// 🙋‍♂️Ques-81 ✅ : Allocate Books using Binary Search : Link -> https://bit.ly/3MLUnC7
int allocateBooks(int arr[], int size, int m){
    int start=0, sum=0;

    for(int i=0; i<size; i++){
        sum+=arr[i];
    }
    int end = sum;
    int ans = -1;

    int mid = start + (end-start)/2;

    while(start<=end){
        bool check = isPossible(arr,size,m,mid);
        if(check){
            ans = mid;
            end = mid-1;
        cout<<"answer: "<<ans<<"mid:"<<mid;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    return ans;
}

//🙋‍♂️Ques-82 ✅ : Painter's Partition Problem -> https://bit.ly/31v3Jiy
int painterproblem(int arr[], int size, int p){
    int start = 0,sum=0;

    for(int i=0; i<size; i++){
        sum+=arr[i];
    }

    int end=sum,ans=-1;
    int mid  = start + (end-start)/2;

    while(start<=end){

        if(isPossible(arr,size,p,mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    return ans;
}

//🙋‍♂️Ques-83 ✅ : Aggressive Cows : Link -> https://bit.ly/3dkuQ2B 
int aggressiveCows(int arr[], int size, int cows ){
    bubbleSort(arr,size);

    int start=arr[1] - arr[0];          //minimum possible distance between cows.
    int end = arr[size-1] - arr[0];     //maximum possible distance between cows.

    int mid = start + (end-start)/2;
    int ans = -1;


    while (start <= end){

        if(isPossibleCows(arr,size,cows,mid)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }

        mid = start + (end-start)/2;
    }

    return ans;
    
}

//🙋‍♂️Ques-84 ✅ : EKO - SPOJ
int ekoSpoj(int arr[],int size, int m){
    int start = 0;
    int maxLength = -1;
    for(int i=0; i<size; i++){
        if(arr[i]>maxLength){
            maxLength = arr[i];
        }
    }
    int end = maxLength;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if(isPossibleHeight(arr,size,m,mid)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }

    return ans;
}

//🙋‍♂️Ques-85 ✅ : PRATA - SPOJ
int prataSpoj(int arr[], int size, int p){
    
    int start = 0, end = 1e7;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end){
        if(isPossibleTime(arr,size,p,mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    return ans;
}

//🙋‍♂️Ques-86 ✔️ : Beautiful Triplets BruteForce - HackerEarth
int beautifulTriplets(int arr[], int size, int d){
    bubbleSort(arr, size);

    int countTriplets = 0;
    int triplets[1000] = {0};
    int tripletsSize = 0;
    
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[j]-arr[i] == d ){
                for(int k=i+1; k<size; k++){
                    if(arr[k]-arr[j] == d){
                        countTriplets++;
                        triplets[tripletsSize] = arr[i];
                        triplets[tripletsSize+1] = arr[j];
                        triplets[tripletsSize+2] = arr[k];
                        tripletsSize+=3;
                    }
                }
            }
        }
    }

    printArr(triplets, tripletsSize);

    return countTriplets;
}

//🙋‍♂️Ques-86 ✔️ : Beautiful Triplets Optimised- HackerEarth
int beautifulTripletsOP(int arr[], int size, int d){
    bubbleSort(arr, size);

    int countTriplets = 0;
    int triplets[1000] = {0};
    int tripletsSize = 0;    

    for(int i=0; i<size-2; i++){
        int j=i+1;
        while(arr[j]-arr[i] <= d && j<size-1){
            if(arr[j]-arr[i] == d){
                int k=j+1;
                while(arr[k]-arr[j] <= d && k<size){
                    if(arr[k]-arr[j] ==d){
                        countTriplets++;
                        triplets[tripletsSize] = arr[i];
                        triplets[tripletsSize+1] = arr[j];
                        triplets[tripletsSize+2] = arr[k];
                        tripletsSize+=3;
                        break;
                    }
                    k++;
                }
            }
            j++;
        }
    }

    printArr(triplets, tripletsSize);

    return countTriplets;
}

//🙋‍♂️Ques-86 ✅ : Beautiful Triplets Optimised using Binary Search [O(NlogN)]- HackerEarth
int beautifulTripletsOPP(int arr[], int size, int d) {
    bubbleSort(arr, size);

    int countTriplets = 0;
    int triplets[1000] = {0};
    int tripletsSize = 0;    

    for(int i=0; i<size-2; i++){
        int j = binarySearchForTriplets(arr,i,i+1,size-1, d);
        if(j != -1){
            int k = binarySearchForTriplets(arr,j,j+1,size, d);
            if(k != -1){

                countTriplets++;
                triplets[tripletsSize] = arr[i];
                triplets[tripletsSize+1] = arr[j];
                triplets[tripletsSize+2] = arr[k];
                tripletsSize+=3;

            }
        }
    }

    printArr(triplets, tripletsSize);

    return countTriplets;
}

int main(){
    cout<<endl<<"~~~~~~~~START~~~~~~~~~~"<<endl<<endl;
    cout<<"Run successfully"<<endl;
    
    // Input array
    int arr[1000] = {0};
    int size = getArr(arr);

    //~~~~~~~~~~~~~ Inputs ~~~~~~~~~~~~~~//

    //💁‍♂️Ques-81 : input number of students,m
    // int m;
    // cout<<"Enter the number of students : ";
    // cin>>m;
    
    //💁‍♂️Ques-82 : input number of Painters,m
    // int m;
    // cout<<"Enter the number of Painters : ";
    // cin>>m;
    
    //💁‍♂️Ques-83 : input length of required wood,m
    // int m;
    // cout<<"Enter the length of wood required : ";
    // cin>>m;
    
    //💁‍♂️Ques-84 : input number of Cows,m
    // int m;
    // cout<<"Enter the number of Cows : ";
    // cin>>m;
    
    //💁‍♂️Ques-85 : input number of Prantha,p
    // int p;
    // cout<<"Enter the number of Prantha : ";
    // cin>>p;

    //💁‍♂️Ques-86 : input the difference
    // int d;
    // cout<<"Enter the value of d : ";
    // cin>>d;

    //~~~~~~~~~ Calling Functions ~~~~~~~~~~~//

    //🙋‍♂️Ques-81 : Allocate Books using Binary Search.
    // int answer = allocateBooks(arr,size,m);
    // cout<<"answer : "<<answer;
    
    //🙋‍♂️Ques-82 : Painter's Partition Problem using Binary Search.
    // int answer = painterproblem(arr,size,m);
    // cout<<"\nAnswer : "<<answer<<endl;

    //🙋‍♂️Ques-83 : Aggressive Cows Problem.
    // int answer = aggressiveCows(arr,size,m);
    // cout<<"\nAnswer : "<<answer<<endl;

    //🙋‍♂️Ques-84 : EKO ekoSpoj
    // int answer = ekoSpoj(arr,size,m);
    // cout<<"\nAnswer : "<<answer<<endl;

    //🙋‍♂️Ques-85 : Prata SPOJ
    // int answer = prataSpoj(arr,size,p);
    // cout<<"\nAnswer : "<<answer<<endl;

    //🙋‍♂️Ques-86 : Beutiful Triplet
    // int answer = beautifulTripletsOPP(arr,size,d);
    // cout<<"\nAnswer : "<<answer<<endl;

    
    cout<<endl<<endl<<"~~~~~~~~~~~~~~~END~~~~~~~~~~~~"<<endl;

}