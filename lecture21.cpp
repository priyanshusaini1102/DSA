#include <iostream>
#include <vector>

using namespace std;

//To input a vector.
vector<int> getVector(){
   
    int size;
    cout<<"Enter the size : ";
    cin>>size;

    vector<int> v;
    cout<<"Enter the elements : ";
    for(int i=0; i<size; i++){
        int input;
        cin>>input;
        v.push_back(input);
    }

    return v;
}

//To print a vector.
void printVector(vector<int> v){
    cout<<"Vector : ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
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

//To reverse a vector.
void reverse(vector<int>& v ){
    int m =-1;
    int start = m+1, end = v.size()-1;

    while( start < end ){
        swap(v[start], v[end]);
        start++;
        end--;
    }

}


//🙋‍♂️Ques-94 ✅ : To rotate an array using vector.
vector<int> rotateArr(vector<int> v, int k){
    vector<int> temp;

    for(int i = 0; i < v.size(); i++){
        temp[(i+k) % v.size()] = v[i];
    }

    //copy temp to v
    v = temp;
}

//🙋‍♂️Ques-95 ✅ : To check whether the array is sorted and rotated.
bool isSortedAndRotated(vector<int> v){
    int count = 0;
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
         count++;
        }
    }

    if(v[v.size()-1] > v[0]) count++;

    return (count <= 1);
}

//🙋‍♂️Ques-96 ✅ : To sum two vectors and store in new vector in elements.
vector<int> sum(vector<int> a, vector<int> b) {
    int i = a.size()-1;
    int j = b.size()-1;

    int carry = 0;

    vector<int> ans;

    while(i>=0 && j>=0 ) {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while(i>=0){
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    while(j>=0){
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    if(carry !=0){       
        int sum = carry;
        ans.push_back(sum);
    }

    reverse(ans);
    return ans;

}

int main(){
    cout<<endl<<"~~~~~~~~START~~~~~~~~~~"<<endl<<endl;
    cout<<"Run successfully"<<endl;
    
    vector<int> v = getVector();

    //Ques-94-To get the value of k.
    // int k;
    // cout<<"Enter the value of k : ";
    // cin>>k;

    //🙋‍♂️Ques-94  : To rotate an array using vector.
    // vector<int> ans = rotateArr(v,k);
    // cout<<"After rotating the vector."<<endl;
    // printVector(ans);

    // 🙋‍♂️Ques-96 : To get second vector.
    vector<int> v2 = getVector();

    //🙋‍♂️Ques-95 : To check whether the array is sorted and rotated.
    // bool ans = isSortedAndRotated(v);
    // if(ans){
    // cout<<"Is vector sorted and rotated ? Answer : True."<<endl;
    // }else{
    // cout<<"Is vector sorted and rotated ? Answer : False."<<endl;
    // }

    //🙋‍♂️Ques-96 : To sum two vectors and store in new vector in elements.
    vector<int> ans = sum(v,v2);
    cout<<"After sum : "<<endl;
    printVector(ans);

    cout<<endl<<endl<<"~~~~~~~~~END~~~~~~~~~~~"<<endl;

}