#include <iostream>
#include <vector>

using namespace std;

void getVector(vector<int>& arr) {
    int n,val;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    cout<<"\nEnter "<<n<<" elements: ";
    for(int i=0; i<n; i++){
        cin>>val;
        arr.push_back(val);
    }
}

//metod overloading
void printVector(vector<int> arr) {
    int n = arr.size();
    cout<<"\nArray :";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}
void printVector(vector<string> arr) {
    int n = arr.size();
    cout<<"\nArray :";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

//🙋‍♂️Ques-144 ✅ - Subsets of integer array - return the Powerset.
void subsets(vector<int> arr, int index, vector<int> output, vector<vector<int>>& ans) {

    if(index>=arr.size()) {
        ans.push_back(output);
        return;
    }

    //exclude 
    subsets(arr,index+1,output,ans);

    //include
    output.push_back(arr[index]);
    subsets(arr,index+1,output,ans);

}

//🙋‍♂️Ques-145 ✅ - returns the subsequences of the string.
void solve(string str, int index, string output, vector<string>& ans) {
    if(index >= str.length()) {
        ans.push_back(output);
        return; 
    }

    //exclude
    solve(str,index+1,output,ans);

    //include
    output = output+str[index];
    solve(str,index+1,output,ans);

}
vector<string> subsequences(string str){
	
	string output;
    vector<string> ans;
	
	solve(str,0,output,ans);
	
	return ans;
	
}

int main(){

    //🙋‍♂️Ques-144 ✅ - Subsets of integer array - return the Powerset.
    // vector<int> arr,output;
    // vector<vector<int>> ans;
    // getVector(arr);
    // subsets(arr,0,output,ans);
    // for(int i=0;i<ans.size(); i++){
    //     printVector(ans[i]);
    // }
    
    //🙋‍♂️Ques-145 ✅ - returns the subsequences of the string.
    // string str,output;
    // vector<string> ans;
    // cout<<"Enter string :";
    // cin>>str;
    // ans = subsequences(str);
    // printVector(ans);

}