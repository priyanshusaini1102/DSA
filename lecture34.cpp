#include <iostream>
#include <vector>

using namespace std;

void getVector(vector<int>& arr){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Enter "<<n<<" elements : ";
    int val;
    for(int i=0; i<n; i++){
        cin>>val;
        arr.push_back(val);
    }
}

void printVector(vector<int> arr){
    cout<<"\nArray : ";
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse(string& s){
    int start = 0, end = s.length()-1;

    while(start < end){
        swap(s[start++], s[end--]);
        
    }
}

//🙋‍♂️Ques-136 ✅: Reverse string using recursion.
void rev(string& s, int start, int end){
    if(start > end) return;

    swap(s[start], s[end]);
    start++;
    end--;
    rev(s, start,end);
}

//🙋‍♂️Ques-137 ✅: To check pallindrome using recursion.
bool checkPallindrome(string s,int start,int end){

    if(s[start] != s[end]) return false;
        
    if(start > end) return true;

    start++;
    end--;

    return checkPallindrome(s, start,end);
}

//🙋‍♂️Ques-138 ✅: To calculate power using recursion.
int power(int a, int b){

    if(b==0) return 1;
    if(b==1) return a;

    int ans = power(a,b/2);

    if(b&1){
        return a * (ans*ans);
    }else{
        return (ans*ans);
    }
}

//🙋‍♂️Ques-139 ✅: To sort an array using recursion.
void bubbleSort(vector<int>& arr, int start, int end){

    if(end == start) return;

    for(int i=start; i<end; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, start, --end);
}

//🙋‍♂️Ques-140 ✅: To sort an array using recursion.
void selectionSort(vector<int>& arr, int start, int end) {
    
    if(start == end) return;

    for(int i=start+1; i<=end; i++){
        if(arr[start] >= arr[i]){
            swap(arr[start], arr[i]);
        }
    }

    start++;
    selectionSort(arr,start,end);

}

//🙋‍♂️Ques-141 ✅: To sort an array using recursion.
void insertionSort(vector<int>& arr, int start, int end) {

    if(start > end) return;

    int temp = arr[start];
    int j = start-1;
    while(j>=0){
        if(arr[j] > temp){
            arr[j+1] = arr[j];
        }else{
            break;
        }
        j--;
    }
    arr[j+1] = temp;

    start++;
    insertionSort(arr,start,end);

}

//🙋‍♂️Ques-141 ✅: To sort an array without using recursion.
void insertionSort1(vector<int>& arr){
    int n = arr.size();
    
    for(int i = 1; i < n; i++){
        int j = i-1;
        int temp = arr[i];
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
    }
    return;
}
      
int main(){

    //🙋‍♂️Ques-136 ✅: Reverse string using recursion.
    // string name = "priyanshu";
    // cout<<"Original Name: "<<name<<endl;
    // rev(name,0,name.length()-1);
    // cout<<"\nReverse name : "<<name<<endl;

    //🙋‍♂️Ques-137 ✅: To check pallindrome using recursion.
    // string name = "abchba";
    // cout<<"Original Name: "<<name<<endl;
    // string ans = (checkPallindrome(name,0,name.length()-1) ? "": "not ");
    // string msg = "It is "+ ans +"a pallindrome.";
    // cout<<msg<<endl;

    //🙋‍♂️Ques-138 ✅: To calculate power using recursion.
    // int a=4,b=3;
    // cout<<"ans : "<<power(a,b)<<endl;

    //🙋‍♂️Ques-139 ✅: To sort an array using recursion.
    // vector<int> arr;
    // getVector(arr);
    // bubbleSort(arr,0,arr.size()-1);
    // printVector(arr);

    //🙋‍♂️Ques-140 ✅: To sort an array using recursion.
    // vector<int> arr;
    // getVector(arr);
    // selectionSort(arr,0,arr.size()-1);
    // printVector(arr); 

    //🙋‍♂️Ques-141 ✅: To sort an array using recursion.   
    // vector<int> arr;
    // getVector(arr);
    // insertionSort(arr,0,arr.size()-1);
    // // insertionSort1(arr);
    // printVector(arr); 

}