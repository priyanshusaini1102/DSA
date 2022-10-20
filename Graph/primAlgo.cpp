#include <bits/stdc++.h>

using namespace std;

void printpq(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q){
    cout<<"\nqueue: ";
    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        int weight = p.first;
        cout<<weight<<" ";
        }
        cout<<endl;
        
}

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

    int sum = 0;
    vector<bool> vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q; //       //<weight,node>
    // priority_queue<int,vector<int>,greater<int>> q;

    
    q.push({0,0}); 
    cout<<"\nsums are ";
    while(!q.empty()){
        printpq(q);

        pair<int,int> front = q.top();
        int node = front.second;
        int weight = front.first;
        //cout<<weight<<" ";
        q.pop();

        if(vis[node]==1) continue;

        vis[node] = 1;
        sum+=weight;
        // cout<<sum<<" ";

        for(auto i:adj[node]){
            if(vis[i.first]!=1){
                q.push({i.second,i.first});
            }
        }


    }

    cout<<"\nMinimal sum weight : "<<sum<<endl;


}