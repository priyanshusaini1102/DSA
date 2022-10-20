#include <bits/stdc++.h>

using namespace std;

int main(){

    //u -> v : edges
    // n : no of nodes and m : no of edges

    int u,v;
    int n,m,w;

    cout<<"\n Enter no of nodes : ";
    cin>>n;

    cout<<"\n Enter no of edges : ";
    cin>>m;

    unordered_map<int,vector<pair<int,int>>> adj;

    for(int i=0;i<m;i++){
        cin>>u;
        cin>>v;
        cin>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=0;i<n;i++){
        cout<<i<<"-> ";
        for(auto j:adj[i]){
            cout<<j.first<<" |"<<j.second<<" "<<", ";
        }
        cout<<endl;
    }

    vector<int> dis(n,INT_MAX);
    dis[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;      //<node,distance>
    q.push({0,0});
    
    while(!q.empty()){

        pair<int,int> front = q.top();
        int node = front.first;
        int distance = front.second;
        q.pop();

        for(auto i: adj[node]){
            if(distance+i.second < dis[i.first]){
                dis[i.first] = distance+i.second;
                q.push({i.first,dis[i.first]});
            }
        }

    }

    cout<<"\nAnswer : ";
    for(int i:dis){
        cout<<i<<" ";
    }
    cout<<endl;

    //sample input : 0 1 2 1 2 5 4 2 1 1 4 4 3 4 3 0 3 1 
    //answer : 0 2 5 1 4

}