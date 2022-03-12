#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    int size = arr.size();
    sort(arr.begin(), arr.end());

    vector<int> ans;
    
    int count = 0;
    
    for(int i=0; i<size;i++){

        if(i<size-1 && arr[i]==arr[i+1]){
            count++;
        }else{
            ans.push_back(count+1);
            count=0;
        }
    }

    sort(ans.begin(), ans.end());
    int ansCounter = ans.size();
    cout<<"ansCOunter: "<<ansCounter<<endl;
    for(int i=1; i<ansCounter; i++){
        if(ans[i] == ans[i-1]){
            return 0;
        }
    }
    return 1;
        
    }

int main(){
    vector<int> arr = {1,2};
    bool answer = uniqueOccurrences(arr);
    cout<<"answer:"<<answer;
}