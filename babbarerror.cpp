vector<int> query_game(int N, vector<int> A, int Q, vector<vector<int>> P){
    vector<int> ans;
    int st,e,temp;
    for(auto i : P){
        int a = i[0];
        int b = i[1] -1;
        int c = i[2] -1;

        switch(a){
            case 1:
                //reverse the array
                st=0,e=A.size()-1;
                while(st<e){
                    temp = A[st];
                    A[st] = A[e];
                    A[e] = temp;
                    s++;
                    e--;
                }
                break;
            case 2:
                //swap(A[b],A[c]);
                    temp = A[b];
                    A[b] = A[c];
                    A[c] = temp;
                break;
            case 3:
                ans.push_back(A[b]);
        }
    }

    return ans;
}







