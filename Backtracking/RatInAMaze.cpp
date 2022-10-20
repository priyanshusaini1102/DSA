//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(int x, int y, int n, vector<vector<int>> &m,vector<vector<bool>> &visited ){
        return ((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0);
    }
    
    void solve(int x, int y,int n, string path, vector<vector<int>> &m, vector<string> &ans, vector<vector<bool>> &visited){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        //Down
        if(isSafe(x+1,y, n, m,visited)){
            path+="D";
            solve(x+1,y,n,path,m,ans,visited);
            
        }
        
        //left
        if(isSafe(x,y-1, n, m,visited)){
            path+="L";
            solve(x+1,y,n,path,m,ans,visited);
        }
        
        //right
        if(isSafe(x,y+1, n, m,visited)){
            path+="R";
            solve(x+1,y,n,path,m,ans,visited);
        }
        
        //up
        if(isSafe(x-1,y, n, m,visited)){
            path+="U";
            solve(x+1,y,n,path,m,ans,visited);
        }
        
        visited[x][y] = 0;
        
        return;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        vector<string> ans;
        string path = "";
        if(m[0][0] == 0) return ans;
        solve(0,0,n,path,m,ans,visited);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends