#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(){

    vector<pair<int,int>> jobs;
    int maxDeadline = 0;
    int n;

    cout<<"\nEnter the total number of jobs : ";
    cin>>n;
    vector<int> done(n,0);

    cout<<"\nEnter the Profit and Deadline of "<<n<<" jobs: "<<endl;
    int u,v;
    for(int i=0; i<n; i++){
        cin>>u>>v;
        jobs.push_back({u,v});
    }

    cout<<"\nJobs are :\n";
    for(int i=0; i<n; i++){
        cout<<i+1<<" -> "<<jobs[i].first<<" "<<jobs[i].second<<endl;
    }


    for(auto i: jobs){
        if(i.second > maxDeadline){
            maxDeadline = i.second;
        }
    }

    sort(jobs.begin(), jobs.end(), comp);

    cout<<"\nAfter sorting, Jobs are :\n";
    for(int i=0; i<n; i++){
        cout<<i+1<<" -> "<<jobs[i].first<<" "<<jobs[i].second<<endl;
    }

    for(auto i:jobs){

        int pos = i.second-1;
        while(pos>=0){
            if(done[pos]==0){
                done[pos] = i.first;
                break;
            }else{
                pos--;
            }
        }

    }

    cout<<"\nAnswer : ";
    for(int i:done){
        cout<<i<<" ";
    }
    cout<<endl;

}