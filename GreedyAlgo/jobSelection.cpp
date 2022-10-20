#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main(){

    vector<pair<int,int>> jobs;
    int n;

    cout<<"\nEnter total number of jobs: ";
    cin>>n;

    cout<<"\nEnter the start and end time of "<<n<<" jobs: "<<endl;
    int u,v;
    for(int i=0; i<n; i++){
        cin>>u>>v;
        jobs.push_back({u,v});
    }

    cout<<"\nJobs are :\n";
    for(int i=0; i<n; i++){
        cout<<i+1<<" -> "<<jobs[i].first<<" "<<jobs[i].second<<endl;
    }

    //Sort the jobs by end time
    sort(jobs.begin(), jobs.end(),comp);

    cout<<"\nAfter sorting, Jobs are :\n";
    for(int i=0; i<n; i++){
        cout<<i+1<<" -> "<<jobs[i].first<<" "<<jobs[i].second<<endl;
    }

    vector<int> ans;
    int currEndTime = 0;
    for(int i=0; i<n; i++){
        if(jobs[i].first>=currEndTime){
            ans.push_back(i+1);
            currEndTime=jobs[i].second;
        }
    }

    cout<<"\nSo, the selected jobs are :";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


}