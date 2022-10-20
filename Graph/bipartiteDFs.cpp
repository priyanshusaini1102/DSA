#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//bipartite using DFS
void bipDFS(unordered_map<int,vector<int>> adj, vector<int> &vis, int i,bool &flag){

    for(int j:adj[i]){
        if(vis[j]==-1){
            vis[j] = vis[i]==0 ? 1 : 0;
            bipDFS(adj,vis,j,flag);
        }else{
            if(vis[j]==vis[i]){
                flag = false;
                return;
            }
        }
    }

}

int main(){

    int u,v;
    int n,m;

    cout<<"\n Enter no of nodes : ";
    cin>>n;

    cout<<"\n Enter no of edges : ";
    cin>>m;

    unordered_map<int,vector<int>> adj;
    vector<pair<int,int>> edges;

    //input adj
    for(int i=0;i<m;i++){
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //print adj
    for(int i=0;i<m;i++){
        cout<<i<<"-> ";
        for(int j:adj[i]){
            cout<<j<<", ";
        }
        cout<<endl;
    }

    bool currColor = 0;
    bool flag = true;
    vector<int> vis(n,-1);
    for(int i=0;i<m;i++){
        if(vis[i]==-1){
            vis[i]=currColor;
            bipDFS(adj,vis,i,flag);
        }
    }

    if(flag){
        cout<<"Bipatite";
    }else{
        cout<<"Not Bipatite";
    }

}