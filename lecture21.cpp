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

//🙋‍♂️Ques-94 ✅ : To rotate an array using vector.
vector<int> rotateArr(vector<int> v, int k){
    vector<int> temp;

    for(int i = 0; i < v.size(); i++){
        temp[(i+k) % v.size()] = v[i];
    }

    //copy temp to v
    v = temp;
}

int main(){
    cout<<endl<<"~~~~~~~~START~~~~~~~~~~"<<endl<<endl;
    cout<<"Run successfully"<<endl;
    
    vector<int> v = getVector();

    //Ques-94-To get the value of k.
    int k;
    cout<<"Enter the value of k : ";
    cin>>k;

    vector<int> ans = rotateArr(v,k);
    cout<<"After rotating the vector."<<endl;
    printVector(ans);

    cout<<endl<<endl<<"~~~~~~~~~END~~~~~~~~~~~"<<endl;

}