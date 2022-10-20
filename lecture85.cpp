#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
template <class T>

class Graph{
    public :
    vector<vector<T>> adj;
    vector<T> ans;

    void addEdge(T u, T v, bool isDirected) {
        if(u>=adj.size()){
            adj.push_back(ans);
        }
        adj[u].push_back(v);

        if(isDirected==false){
            if(v>=adj.size()){
                adj.push_back(ans);
            }
            adj[v].push_back(u);
        }
    }

    void printGraph() {
        for(int i=0;i<adj.size();i++){
            cout<<i;
            for(auto j: adj[i]){
                cout<<"->"<<j; 
            }
            cout<<endl;
        }
    }
};

int main(){

    Graph<int> g;

    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.printGraph();

    return 0;
}