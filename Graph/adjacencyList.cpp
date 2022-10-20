#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//DFS
/*
// void DFS(unordered_map<int,vector<int>> adj, vector<int> &ans, vector<int> &vis, int i){
//     ans.push_back(i);

//     vis[i] = 1;

//     for(int c: adj[i]){
//         if(vis[c]!=1){
//             DFS(adj,ans,vis,c);
//         }
//     }
// }
*/

//detect cycle using DFS
/*
void checkCycle(unordered_map<int,vector<int>> adj, vector<int> &vis, int i,bool &flag){
    if(vis[i]==1){
        flag = true;
        return;
    }

    vis[i] = 1;

    for(int c: adj[i]){
        if(vis[c]!=1){
            checkCycle(adj,vis,c,flag);
        }
    }

}
*/

bool checkCycle(unordered_map<int,vector<int>> adj, vector<int> &vis, int i){
    
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        if(vis[front]==1) return true;

        vis[front] = 1;

        for(int j :adj[front]){
            if(!vis[j]){
                q.push(j);
            }
        }
    }

    return false;

}

//Bipartite graph using BFS
void bipBFS(unordered_map<int,vector<int>> adj, vector<int> &vis, int i,bool &flag){
    
    queue<int> q;
    int currColor = 0;
    vis[i] = currColor;
    q.push(i);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int j :adj[front]){
            if(vis[j] == -1){
                vis[j] = vis[front]==1 ? 0 : 1;
                q.push(j);
            }else{
                if(vis[j] == vis[front]){
                    flag = false;
                    return;
                }
            }
        }
    }

    flag = true;

}



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

/*
    cout<<"\n Enter the "<<m<<" edges : \n";
    for(int i=0;i<m;i++){
        cin>>u;
        cin>>v;
        edges[i].first = u;
        edges[i].second = v;
    }
*/

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

    //

    //DFS
    /*
    vector<int> ans;
    vector<int> vis(m,0);
    for(int i=1;i<=m;i++){
        if(vis[i]!=1){
            DFS(adj,ans,vis,i);
        }
    }

    cout<<"\nDFS is ";
    //printing DFS
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    */

    //detect a cycle using BFS
    /*
    vector<int> visited(m,0);
    bool flag = false;
    for(int i=0;i<m;i++){
        if(!visited[i]){
            checkCycle(adj, visited,i,flag);
        }
    }

    if(flag){
    cout<<"\nThere is cycle detected."<<endl;

    }else{
    cout<<"\nThere is no cycle detected."<<endl;
    }
    */
   
   // detect a cycle using DFS
   /*
   vector<int> visited(m,0);
   for(int i=0; i<m;i++){
    if(!visited[i]){
        if(checkCycle(adj,visited,i)){
            cout<<"\nCycle detected";
            return 0;
        }
    }
   }
   cout<<"\nCycle not detected.";
   */


    //bipartite graph using bfs
    /*
    vector<int> visited(m,-1);
    bool flag = false;
    for(int i=0;i<m;i++){
        if(!visited[i]){
            bipBFS(adj, visited,i,flag);
        }
    }

    if(flag){
    cout<<"\nThis is bipartite graph."<<endl;

    }else{
    cout<<"\nThis is not bipartite graph."<<endl;
    }
    */


}