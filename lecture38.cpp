#include <iostream>
#include <vector>

using namespace std;

void getVector(vector<int>& arr){
    int n,val;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0; i<n; i++){
        cin>>val;
        arr.push_back(val);
    }
}

void printVector(vector<string> arr){
    int n  = arr.size();
    cout<<"\nArray: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

//🙋‍♂️Ques-146 ✅ - Phone Keypad☎️ recursion problem.
void solve(string digits, int index, string output,vector<string> mapping,vector<string>& ans){
    cout<<"\nOutput : "<<output<<endl;
    if(index >= digits.size()){
        ans.push_back(output);
        return;
    }

    int digit = digits[index] - '0';            //⚠️ don't forget digits is a string arary.
    cout<<"\nDigit : "<<digit<<endl;
    string str = mapping[digit];

    for(int i=0; i<str.length(); i++){
        output.push_back(str[i]);               //☑️ string str work as vector<char> str because we can use str.push_back(ch);
        solve(digits,index+1,output,mapping,ans);
        output.pop_back();
    }

}

void phone(string digits, vector<string>& ans){
    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,0,"",mapping,ans);
}

vector<string> findPossibleWords(string s)
{
	vector<string> ans;
	phone(s,ans);
	return ans;
}

int main(){

    string digits;
    cout<<"Enter digits : ";
    cin>>digits;
    vector<string> ans = findPossibleWords(digits);
    // phone(digits,ans);
    printVector(ans);

}