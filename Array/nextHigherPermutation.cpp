#include <bits/stdc++.h> 
using namespace std;
// 
// vector<int> nextPermutation(vector<int> &permutation, int n)
// {
//     vector<int> ans;
//     if(n==1) return permutation;
//     int smallestIndex = n-1;
//     for(int i=n-2;i>=0;i--){
//         if(permutation[i] < permutation[smallestIndex]){
//             smallestIndex = i;
//             break;
//         }
//     }
//     cout<<"smallestIndex : "<<smallestIndex<<endl;
//     for(int i=n-1;i>smallestIndex;i--){
//         swap(permutation[i],permutation[i-1]);
//     }
//     return permutation;
    
// }

void nextPermutation(vector<int>& permutation) {
    int n = permutation.size();
    bool flag = 0;
    
    if(n==1) return;
    if(n==2){
            swap(permutation[0],permutation[1]);
            return;
    }
    
    int end = n-1,start = 0;
        
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(permutation[j] < permutation[i]){
                start = j;
                end = i;
                break;
            }  
        }
    }
    
    for(int i=end;i>start;i--){
        swap(permutation[i],permutation[i-1]);
        flag = true;
    }
    
    if(flag == false){
        sort(permutation.begin(),permutation.end());
    }
    
    }

int main(){
    int n;
    cin>>n;

    vector<int> permutation;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        permutation.push_back(num);
    
    }

    nextPermutation(permutation);

    cout<<"Permutation : ";
    for(int i=0;i<n;i++){
        cout<<permutation[i]<<" ";
    }
    cout<<endl;

}