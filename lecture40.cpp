#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<string> arr){
    int n = arr.size();
    cout<<"\nArray : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//🙋‍♂️Ques-148 ✅ - Rat🐀 in a maze problem.
bool isPossible(int newx, int newy,vector<vector<int>>& arr,int n,vector<vector<int>>& visited){
    
    if(newx>=0 && newx<n && newy>=0 && newy<n && arr[newx][newy]==1 && visited[newx][newy]==0){
        return true;
    }else{
        return false;
    }
}

void solve(vector<vector<int>> arr,int n,int x,int y,string path,vector<vector<int>> visited, vector<string>& ans){

    if(x==(n-1) && y==(n-1)){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    //Up☝️
    int newx = x-1;
    int newy = y;
    if(isPossible(newx,newy,arr,n,visited)){
        path.push_back('U');
        solve(arr,n,newx,newy,path,visited,ans);
        path.pop_back();
    }

    //Down👇
    newx = x+1;
    newy = y;
    if(isPossible(newx,newy,arr,n,visited)){
        path.push_back('D');
        solve(arr,n,newx,newy,path,visited,ans);
        path.pop_back();
    }

    //Left👈
    newx = x;
    newy = y-1;
    if(isPossible(newx,newy,arr,n,visited)){
        path.push_back('L');
        solve(arr,n,newx,newy,path,visited,ans);
        path.pop_back();
    }

    //Right👉
    newx = x;
    newy = y+1;
    if(isPossible(newx,newy,arr,n,visited)){
        path.push_back('R');
        solve(arr,n,newx,newy,path,visited,ans);
        path.pop_back();
    }

    visited[x][y] = 0;

}

vector <string> searchMaze(vector<vector<int>> & arr, int n) {
    vector<string> ans;
    if(arr[0][0] == 0) return ans;
    vector<vector<int>> visited = arr;
    for(int i = 0; i < n; i++) {
        for(int j=0; j<n;j++) {
            visited[i][j] = 0;
        }
    }
    solve(arr,n,0,0,"", visited,ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n,val;
    vector<vector<int>> arr;
    cout<<"Enter the value of n :";
    cin>>n;
    for(int i=0; i < n; i++){
        vector<int> a;
        for(int j=0; j < n; j++){
            cin>>val;
            a.push_back(val);
        }
        arr.push_back(a);
    }

    vector<string> ans = searchMaze(arr,n);
    printVector(ans);

}