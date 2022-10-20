#include <bits/stdc++.h>

using namespace std;

int maxSum(int arr[], int N, int k)
{
    // MS[i] is going to store maximum sum
    // subsequence in subarray from arr[i]
    // to arr[n-1]
    int MS[N];
 
    // We fill MS from right to left.
    MS[N - 1] = arr[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (i + k + 1 >= N)
            MS[i] = max(arr[i], MS[i + 1]);
        else
            MS[i] = max(arr[i] + MS[i + k + 1], MS[i + 1]);
    }
 
    return MS[0];
}


int minCOST(int N , int K, vector<vector<int>>A){
    /*
    int sum2=0,sum3=0;

    int sumCost = 0;

    for(int i=0;i<N;i++){
        for(int j=1; j<3; j++){
            if(j==1){
                if(A[i][j]){
                    sum2+=A[i][j];
                    sumCost+=A[i][0];
                }

            }else{
                if(A[i][j]){
                    sum3+=A[i][j];
                    sumCost+=A[i][0];
                }
            }

        }

        if(sum2>=K || sum3>=K){
            return sumCost; 
        }
    }

    return sumCost;
    */

   string str = "priyanshu";
   cout<<str.substr(0,0);

}

int main() {
    
   string str = "priyanshu";
   cout<<str.substr(0,1);
}