#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

printVector(vector<string> ans){
    int n = ans.size();

    cout<<"\n Array: ";
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}

//🙋‍♂️Ques-147 ✅ - String permutations.
void solve(string str,int index, vector<string>& ans){

    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int i=index; i<str.length(); i++){
        swap(str[index], str[i]);
        solve(str,index+1,ans);
        swap(str[index], str[i]);
    }

}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    solve(str,0,ans);
    sort(ans.begin(), ans.end());
    return ans;
}

// asd ads sad sda das dsa
// ads asd das dsa sad sda          //sort ans for this answer.

int main(){

    string str;
    cout<<"Enter the string to generate permutations : ";
    cin>>str;

    vector<string> ans = generatePermutations(str);
    printVector(ans);


}