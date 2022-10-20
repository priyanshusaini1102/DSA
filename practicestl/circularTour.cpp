#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int firstCircularTour(vector<int> &petrol, vector<int> &distance, int N)
{
    for (int i = 0; i < N; i++)
    {
        int start = i, end = i;
        int currP = 0;
        cout << "\nFor " << i + 1 << " block.";
        do
        {
            currP += petrol[end] - distance[end];
            if (currP < 0)
            {
                break;
            }
            else
            {
                end = (end == N - 1) ? 0 : ++end;
            }
        } while (start != end);

        if (start == end && currP >= 0)
        {
            return i;
        }
    }

    return -1;
}
int funn(int a, int b)
{

    if ((a ^ b) > (3 - a) && (5 + a) < (a ^ b))
    {
        b = 1 + b + a;
        a = 1 + b + b;
        b = (b + 2) + a;
        funn(b, b) - a;
    }
    else
    {
        b = (b + 2) + b;
        return b - a;
    }
}

int main()
{
    // vector<int> petrol = {4,6,7,4};
    // vector<int> distance = {6,5,3,5};
    // int N = petrol.size();
    // cout<<firstCircularTour(petrol,distance,N)<<endl;

    // pair<int,int> currState;
    // currState = make_pair(12,12);

    // pair<int,int> maxState;
    // maxState = currState;

    // cout<<maxState.first<<" "<<maxState.second<<endl;

    // map<int,bool> m;
    // cout<<m[1];

    // int arr[4] = {1,2,3,5};
    // int n = 5;
    // int ans = 0;
    // for(int i=1;i<=n;i++) {
    //     ans=ans^i;
    // }

    // for(int i:arr){
    //     ans = ans^i;
    // }

    // cout<<"\nMissing element : "<<ans<<endl;

    // int a =8, b=7;
    // cout<<funn(a,b);

    if (-1)
    {
        cout<<"h";
    }
    else
    {
        cout<<"f";
    }

    int i = 2;

    int ans = !i;
    cout<<ans;
}

int leastDifference(int arr[], int length, int n)
{
    int minDiff = INT_MAX;
    for (int i = 0; i < length; i++)
    {
        int diff = (n > arr[i]) ? n - arr[i] : arr[i] - n;
        minDiff = diff < minDiff ? diff : minDiff;
    }
    return minDiff;
}