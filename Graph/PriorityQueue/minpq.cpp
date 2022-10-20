#include <bits/stdc++.h>

using namespace std;

int main()
{
    pair<int,int> value;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    pq.push({1,9});
    pq.push({2,8});
    pq.push({3,7});

    while(!pq.empty())
    {
        value = pq.top();
        pq.pop();
        cout<<value.first<< " ";
    }
    return 0;
}