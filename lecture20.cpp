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

//🙋‍♂️Ques-90 ✅ : To reverse the vector
vector<int> reverse(vector<int> v, int m ){
    int start = m+1, end = v.size()-1;

    while( start < end ){
        swap(v[start], v[end]);
        start++;
        end--;
    }

    return v;
}

//🙋‍♂️Ques-91 ✅ : To merge 2 sorted arrays.
vector<int> mergeVectors(vector<int> v,vector<int> v2){
    vector<int> merge;
    int i=0,j=0;

    while(i<v.size() && j<v2.size()){
        if(v[i]<v2[j]){
            merge.push_back(v[i]);
            i++;
        }else{
            merge.push_back(v2[j]);
            j++;
        }
    }
    while(i<v.size()){
        merge.push_back(v[i]);
        i++;
    }
    while(j<v2.size()){
        merge.push_back(v2[j]);
        j++;
    }

    return merge;
}

//🙋‍♂️Ques-92 ✅ : To merge 2 sorted arrays in first.
vector<int> mergeVectorsInFirst(vector<int> v,int m ,vector<int> v2, int n){

    int i = m-1, j = n-1, lastPlace = m+n-1;

    while(i>=0 && j>=0){
        v[lastPlace--] = v[i] > v2[j] ? v[i--] : v2[j--];
    }

    return v;
}

//🙋‍♂️Ques-93 ✅ : To move zeros to the right.
vector<int> moveZeros(vector<int> v){
    int nonZero = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] != 0){
            swap(v[nonZero++], v[i]);
        }
    }

    return v;
}

int main(){
    
    vector<int> v = getVector();
    

    //INPUTS//

    //💁‍♂️Ques-90 : To get the value of m.
    // int m;
    // cout<<"Enter the value of m : ";
    // cin>>m;

    //💁‍♂️Ques-91 : To get input second vector.
    // int size2;
    // cout<<"Enter the size : ";
    // cin>>size2;
    // vector<int> v2 = getVector(size2);

    //💁‍♂️Ques-92 : To get the actual size of v
    // int m;
    // cout<<"Enter the value of m : ";
    // cin>>m;


    //CALLING FUNCTION//

    //🙋‍♂️Ques-90  : To reverse the vector
    // vector<int> rev = reverse(v,1);
    // printVector(rev);

    //🙋‍♂️Ques-91 : To merge 2 sorted arrays.
    // vector<int> merge = mergeVectors( v, v2);
    // cout<<"After merge : \n";
    // printVector(merge);

    //🙋‍♂️Ques-92 : To merge 2 sorted array in first
    // vector<int> merge = mergeVectorsInFirst(v,m, v2,size2);
    // printVector(merge);

    //🙋‍♂️Ques-93 : To move zeros to right.
    vector<int> res = moveZeros(v);
    printVector(res);

    cout << endl;


}