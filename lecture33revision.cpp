#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

void getArray(int arr[], int &n){
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter "<<n<< "elements in array :";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    } 
}

void printArr(int arr[], int n){
    cout<<"Array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void getVector(vector<int> &v){
    int val,n;
    cout<<"Enter the size of array :";
    cin>>n;
    cout<<"\nEnter "<<n<<" elements in array : ";
    for(int i=0; i<n; i++){
        cin>>val;
        v.push_back(val);
    }

}

//🙋‍♂️Ques-123 ✅ : binary search in array using recursion.
int binarySearch(int arr[],int key, int start, int end){
    int mid = start + (end-start)/2;

    if(start > end) return -1;

    if(arr[mid] == key) {
        return mid;
    }

    if(arr[mid] > key){ 
        binarySearch(arr,key,start, mid-1);
    }else{
        binarySearch(arr,key,mid+1,end);
    }
}

//🙋‍♂️Ques-124 ✅ : return the first and the last occurrence of the given element in the array.
int firstOcc(int arr[],int key,int start,int end,int ans=-1){

    if(start > end){
        return ans;
    }

    int mid = start + (end-start)/2;

    if(key <= arr[mid]){
        if(key == arr[mid]){
        ans = mid;
        }
        firstOcc(arr,key,start,mid-1,ans);
    }else{
        firstOcc(arr,key,mid+1,end,ans);
    }

}

int lastOcc(int arr[],int key, int start,int end, int ans = -1){

    if(start > end){
        return ans;
    }

    int mid = start + (end-start)/2;

    if(key >= arr[mid]){
        if(key == arr[mid]){
        ans = mid;
        }
        lastOcc(arr,key,mid+1,end,ans);
    }else{
        lastOcc(arr,key,start,mid-1,ans);
    }

}

pair<int,int> firstAndLastOcc(int arr[],int n, int key){
    pair<int,int> ans;
    ans.first = firstOcc(arr,key,0,n-1);
    ans.second = lastOcc(arr,key,0,n-1);
    return ans;
}

//🙋‍♂️Ques-125 ✅ : return the peak index in a mountain array. - {1,3,5,6,4,3,2}
int peakIndex(int *arr,int start,int end){
    if(start > end) return -1;
    
    if(start == end) return start;

    int mid = start + (end-start)/2;

    if(arr[mid]< arr[mid+1]){
        peakIndex(arr,mid+1,end);
    }else{
        peakIndex(arr,start,mid);
    }
}

//🙋‍♂️Ques-126 ✅ : to find the pivot(balanced point) in the array. (exclude of binary search topic)
int findPivot(int *arr,int n,int leftSum,int rightSum,int i=-1){
    cout<<"\n leftSum: "<<leftSum<<" rightSum: "<<rightSum<<endl;
    if(leftSum>rightSum) return -1;
    if(leftSum==rightSum) return i;

    i++;
    rightSum = rightSum - arr[i];
    if(i>0){
        leftSum = leftSum + arr[i-1];
    }
  
    return findPivot(arr,n,leftSum,rightSum,i);
}

int midIndex(int *arr,int n){
    int rightSum = 0,leftSum = 0;
    
    for(int i=0;i<n;i++){
        rightSum+=arr[i];
    }

    return findPivot(arr,n,leftSum,rightSum);
}

//🙋‍♂️Ques-127 ✅ :to find pivot in an sorted and rotated array.
int pivotIndex(int *arr,int start,int end) {
    
    if(start == end) return start;

    int mid = start + (end-start)/2;

    if(arr[0] > arr[mid]){
        return pivotIndex(arr,start,mid);
    }else{
        return pivotIndex(arr,mid+1,end);
    }

}

//🙋‍♂️Ques-128 ✅ : to find given element in sorted and rotated array. - {use - binarySearch(), pivotIndex()}
int binarySearchInSortedAndRotated(int *arr,int n,int key){
    int pivot = pivotIndex(arr,0,n-1);

    if(key < arr[0]){
        return binarySearch(arr,key,pivot,n-1);
    }else{
        return binarySearch(arr,key,0,pivot-1);
    }
}

//🙋‍♂️Ques-129 ✅ : to find square root with precision using recursion and binary search.
int sqrtWithoutPrecision(int num,int end,int start=0,int ans=-1){

    if(start > end) return ans;

    int mid = start + (end-start)/2;

    if(mid*mid <=num){
        ans = mid;
        sqrtWithoutPrecision(num,end,mid+1,ans);
    }else{
        sqrtWithoutPrecision(num,mid-1,start,ans);
    }

}

double sqrtWithPrecision(int num,int factor,double end,double start=0,double ans=-1 ){
    
    if(start > end) return ans;

    double mid = start + (end-start)/2;

    if(mid*mid <= num){
        ans = mid;
        return sqrtWithPrecision(num,factor,end,(mid+(1.0/factor)),ans);
    }else{
        return sqrtWithPrecision(num,factor,(mid-(1.0/factor)),start,ans);
    }

}

double preciseSqrt(int num,int precision){
    cout<<"precised";
    int sqrt = sqrtWithoutPrecision(num,num);

    int factor=1;
    for(int i=0;i<precision;i++){
        factor*=10;
    }

    double precSqrt = sqrtWithPrecision(num,factor,sqrt+1,sqrt);

    return precSqrt;
}

//🙋‍♂️Ques-130 ✅ : Allocate books using binary search and recusion.
bool isPossible(int arr[], int n, int s,int mid){

    int student = 1;
    int sumPages = 0;
    
    for(int i = 0; i < n; i++){
        if((sumPages+ arr[i]) <= mid){
            sumPages+=arr[i];
        }else{
            student++;
            if(student>s || arr[i]>mid) return false;
        }
    }
    return true;

}

int allocateBooks(int arr[],int n,int s,int start,int end,int ans = -1){

    int mid = start + (end-start)/2;

    if(start > end) return ans;

    if(isPossible(arr,n,s,mid)){
        ans = mid;
        allocateBooks(arr,n,s,start,mid-1,ans);
    }else{
        allocateBooks(arr,n,s,mid+1,end,ans);
    }

}

int bookAllocation(int arr[],int n, int s){

    int start=0,end=0;
    for(int i=0;i<n;i++){
        end+=arr[i];
    }
    return allocateBooks(arr,n,s,start,end);
}

//🙋‍♂️Ques-131 ✅ : Painter's Partition Problem.
int allocatePartition(int arr[],int n,int p,int start,int end,int ans = -1){
    // cout<<"\nstart: "<<start<<", end: "<<end<<" ans: "<<ans;
    // cout<<" mid: "<<mid;
    if(start > end) return ans;

    int mid = start + (end-start)/2;

    if(isPossible(arr,n,p,mid)){
        ans = mid;
        return allocatePartition(arr,n,p,start,mid-1,ans);
    }else{
        return allocatePartition(arr,n,p,mid+1,end,ans);
    }

}

int partitionAllocation(int arr[],int n,int p){

    int start=0,end=0;
    for(int i=0;i<n;i++){
        end+=arr[i];
    }

    return allocatePartition(arr,n,p,start,end);

}

//🙋‍♂️Ques-132 ✅: Aggressive Cows 🐄🐄🐄
bool isPossible(vector<int> stalls,int mid,int c){
	int n = stalls.size();
	int cow = 1;
	int cowPos1 = stalls[0];
	for(int i=0; i<n;i++){
		if(stalls[i]-cowPos1 >=mid){
			cowPos1 = stalls[i];
			cow++;
			
		}
	}
	if(cow < c){
		return false;
	}else{
		return true;
	}
}

int assignCows(vector<int> stalls, int start, int end, int c,int ans=-1){
	if(start > end) return ans;
	
	int mid = start + (end-start)/2;
	
	if(isPossible(stalls,mid,c)){
		ans = mid;
		return assignCows(stalls,mid+1,end,c,ans);
	}else{
		return assignCows(stalls,start,mid-1,c,ans);
	}
	
}

int aggressiveCows(vector<int> &stalls, int k)
{
	sort(stalls.begin(),stalls.end());
	int n = stalls.size();
    int min=stalls[0],max=stalls[0];
	for(int i=1;i<n;i++){
		if(stalls[i]>max){
			max = stalls[i];
		}
		if(stalls[i]<min){
			min = stalls[i];
		}
	}
	int start=0,end=max-min;
	return assignCows(stalls,start,end,k);
}

//🙋‍♂️Ques-133 ✅ : EKO-Spoj
bool isPossibleHeight(vector<int> trees, int k, int mid){
    int sumWood = 0;

    for(int i=0; i<trees.size(); i++){
        if(trees[i] > mid){
            sumWood += (trees[i] - mid);
            if(sumWood >= k) return true;
        }
    }
    return false;
}

int cutTrees(vector<int> trees, int k, int start, int end, int ans = -1){

    if(start > end) return ans;

    int mid = start + (end-start)/2;

    if(isPossibleHeight(trees,k,mid)){
        ans = mid;
        return cutTrees(trees,k,mid+1,end,ans);
    }else{
        return cutTrees(trees,k,start,mid-1,ans);
    }

}

int ekoSpoj(vector<int> trees, int k){
    int start=0,end=0;
    for(int i=0;i<trees.size(); i++){
        if(trees[i] > end){
            end = trees[i];
        }
    }

    return cutTrees(trees, k, start, end);
}

//🙋‍♂️Ques-134 ✅ : Prata-Spoj
bool isPossibleTime(vector<int> chefs, int k, int mid){
    int time=0,prata=1,totalPrata=0;

    for(int i=0; i<chefs.size(); i++){
        prata=0,time=0;
        while((time+((prata+1)*chefs[i]))<=mid){
            time+=(++prata*chefs[i]);
            // cout<<"\n chef : "<<(i+1)<<" prata: "<<prata;
        }
        totalPrata+=prata;
        // cout<<" totalPrata : "<<totalPrata<<endl;
        if(totalPrata>=k) return true;
    }

    return false;
}

int prataTime(vector<int> chefs, int k, int start, int end, int ans = -1){
    // cout<<"\nstart: "<<start<<", end: "<<end<<" ans: "<<ans;
    
    if(start > end) return ans;

    int mid = start + (end-start)/2;
    // cout<<" mid: "<<mid;
    if(isPossibleTime(chefs,k,mid)){
        ans = mid;
        return prataTime(chefs,k,start,mid-1,ans);        
    }else{
        return prataTime(chefs,k,mid+1,end,ans);
    }

}

int prataSpoj(vector<int> chefs,int k){
    int start=0,end=1e7;
    sort(chefs.begin(), chefs.end());
    return prataTime(chefs,k,start,end);

}

//🙋‍♂️Ques-135 : Beautiful Triplets 
int binarySearch(vector<int> arr,int k, int start, int end){
    
    if(start > end) return -1;
    
    int mid = start + (end-start)/2;
    
    if(arr[mid] == k){
        return mid;
    }
    
    if(arr[mid] > k){
        return binarySearch(arr, k, start, mid-1);
    }else{
        return binarySearch(arr, k, mid+1, end);
    }
    
}

int beautifulTriplets(int d, vector<int> arr) {

    int i,j,k,count=0;
    for(i=0;i<arr.size() - 2; i++){
        j=i+1;
        int k=-1;
        int j = binarySearch(arr, (arr[i]+d), i+1, arr.size()-2);
        if(j!= -1){
            k = binarySearch(arr, (arr[j]+d), j+1, arr.size()-1);
        }
        if(k != -1){
            count++;
        }
        
    }
    return count;

}


int main(){

    //🙋‍♂️Ques-123 ✅ : binary search in array using recursion.
    // int arr[MAX];
    // int size;
    // getArray(arr,size);
    // int key;
    // cout<<"Enter the value of key to found : ";
    // cin >> key;
    // int foundIndex =  binarySearch(arr,size,key,0,size-1);
    // cout<<"foundIndex: "<<foundIndex<<" value: "<<(foundIndex != -1 ? arr[foundIndex] : NULL )<<endl;

    //🙋‍♂️Ques-124 ✅ : return the first and the last occurrence of the given element in the array.
    // int arr[MAX];
    // int size;
    // getArray(arr,size);
    // int key;
    // cout<<"Enter the value of key to found : ";
    // cin >> key;
    // pair<int,int> foundIndexes = firstAndLastOcc(arr,size,key);
    // cout<<foundIndexes.first<<" "<<foundIndexes.second<<endl;

    //🙋‍♂️Ques-125 ✅ : return the peak index in a mountain array. - {1,3,5,6,4,3,2}
    // int arr[MAX];
    // int size;
    // getArray(arr,size);
    // int foundIndex = peakIndex(arr,0,size-1);
    // cout<<"Peak Index : "<<foundIndex<<" and Value at peak index : "<<arr[foundIndex]<<endl;

    //🙋‍♂️Ques-126 ✅ : to find the pivot(balanced point) in the array. (exclude of binary search topic)
    // int arr[MAX];
    // int size;
    // getArray(arr,size);
    // int foundIndex = midIndex(arr,size);
    // cout<<"Pivot Index is : "<<foundIndex<<" and Value at peak index : "<<arr[foundIndex]<<endl;

    //🙋‍♂️Ques-127 ✅ :to find pivot in an sorted and rotated array.
    // int arr[MAX];
    // int size;
    // getArray(arr,size);
    // int foundIndex = pivotIndex(arr,0,size-1);
    // cout<<"Pivot Index : "<<foundIndex<<" and Value at pivot index : "<<arr[foundIndex]<<endl;
     
    //🙋‍♂️Ques-128 ✅ : to find given element in sorted and rotated array.
    // int arr[MAX];
    // int size;
    // getArray(arr,size);
    // int key;
    // cout<<"Enter the value of key to found : ";
    // cin >> key;
    // int foundIndex = binarySearchInSortedAndRotated(arr,size,key);
    // cout<<"Fount at key : "<<foundIndex<<endl;

    //🙋‍♂️Ques-129 ✅ : to find square root with precision using recursion and binary search. - {Time Complexity - O(n)}
    // int num;
    // cout<<"Enter any number :";
    // cin>>num;
    // double sqrt = preciseSqrt(num,4);
    // cout<<"Square root of "<<num<<" = "<<sqrt<<endl;

    //🙋‍♂️Ques-130 ✅ : Allocate books using binary search and recusion.
    // int arr[MAX];
    // int size;
    // getArray(arr,size);
    // int s;
    // cout<<"Enter the number of students : ";
    // cin>>s;
    // int ans = bookAllocation(arr,size,s);
    // cout<<"\nAnswer : "<<ans<<endl;

    //🙋‍♂️Ques-131 ✅ : Painter's Partition Problem.
    // int arr[MAX];
    // int size;
    // getArray(arr,size);
    // int p;
    // cout<<"Enter the number of painters : ";
    // cin>>p;
    // int ans = partitionAllocation(arr,size,p);
    // cout<<"\nAnswer : "<<ans<<endl;

    //🙋‍♂️Ques-132 ✅: Aggressive Cows 🐄🐄🐄
    // vector<int> stalls;
    // getVector(stalls);
    // int c;
    // cout<<"Enter the number of aggressive cows : ";
    // cin>>c;
    // int ans = aggressiveCows(stalls,c);
    // cout<<"\nAnswer : "<<ans<<endl;

    //🙋‍♂️Ques-133 ✅ : EKO-Spoj
    // vector<int> trees;
    // getVector(trees);
    // int k;
    // cout<<"Enter the required length of wood : ";
    // cin>>k;
    // int ans = ekoSpoj(trees,k);
    // cout<<"\nAnswer : "<<ans<<endl;

    //🙋‍♂️Ques-134 ✅ : Prata-Spoj
    // vector<int> chefs;
    // getVector(chefs);
    // int k;
    // cout<<"Enter the required prata : ";
    // cin>>k;
    // int ans = prataSpoj(chefs,k);
    // cout<<"\nAnswer : "<<ans<<endl;

    //🙋‍♂️Ques-135 ✅ : Beautiful Triplets
    // vector<int> arr;
    // getVector(arr);
    // int d;
    // cout<<"Enter the value of d : ";
    // cin>>d;
    // int ans = beautifulTriplets(d,arr);
    // cout<<"\nAnswer : "<<ans<<endl;

}