#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void DFS(unordered_map<int,vector<int>> adj,vector<int> &vis,stack<int> &st, int i){

    vis[i] = 1;

    for(int c: adj[i]){
        if(vis[c]!=1){
            DFS(adj,vis,st,c);
        }
    }
    st.push(i);
}

//kahn's algorithm


int main(){

    //u -> v : edges
    // n : no of nodes and m : no of edges

    int u,v;
    int n,m;

    cout<<"\n Enter no of nodes : ";
    cin>>n;

    cout<<"\n Enter no of edges : ";
    cin>>m;

    unordered_map<int,vector<int>> adj;
    vector<pair<int,int>> edges;
    cout<<"\nEnter the edges:\n";
    for(int i=0;i<m;i++){
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    vector<int> inDeg(m,0);
    for(int i=0;i<m;i++){
        cout<<i<<"-> ";
        for(int j:adj[i]){
            inDeg[j]++;
            cout<<j<<", ";
        }
        cout<<endl;
    }

    //indegree printing
    cout<<"\nindeg : ";
    for(int i:inDeg){
        cout<<i<<" ";
    }
    cout<<endl;
    queue<int> q;

    for(int j=0;j<inDeg.size();j++){

        if(inDeg[j]==0){
            q.push(j);
        }

    }
    vector<int> ans;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(int i:adj[front]) {
            inDeg[i]--;
            if(inDeg[i]==0){
                q.push(i);
            }
        }

    }

    cout<<"\n Answer : ";
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;


    




    /*
    stack<int> st;

    vector<int> ans;
    vector<int> vis(m,0);
    for(int i=1;i<m;i++){
        if(vis[i]!=1){
            DFS(adj,vis,st,i);
        }
    }
    

    //stack to answer
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }



    cout<<"\nTopological sort is ";
    //printing DFS
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    */

}