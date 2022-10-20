#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    //u -> v : edges
    // n : no of nodes and m : no of edges

    int u,v;
    int n,m;

    cout<<"\n Enter no of nodes : ";
    cin>>n;

    cout<<"\n Enter no of edges : ";
    cin>>m;

    unordered_map<int,vector<<int>>> adj;
    vector<pair<int,int>> edges;
    cout<<"\nEnter the edges:\n";
    for(int i=0;i<m;i++){
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
         adj[v].push_back(u);
    }


    for(int i=0;i<m;i++){
        cout<<i<<"-> ";
        for(int j:adj[i]){
            cout<<j<<", ";
        }
        cout<<endl;
    }

    vector<int> ans(m,INT_MAX);

    ans[0] = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty()){

        int front = q.front();
        q.pop();

        for(int i:adj[front]){
            if(ans[front]+1 < ans[i]){
                ans[i] = ans[front]+1; 
                q.push(i);
            }
        }

    }

    cout<<"\nAnswer : ";
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

}