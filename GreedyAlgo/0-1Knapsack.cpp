#include <bits/stdc++.h>

using namespace std;

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
    return a.first.second > b.first.second;
}

int main(){

    vector<pair<pair<int,int>,int>> products;
    int n,bag;

    cout<<"\nEnter the total number of products: ";
    cin>>n;

    cout<<"\nEnter the capacity of bag : ";
    cin>>bag;

    cout<<"\nEnter the weight and price of"<<n<<" products: "<<endl;
    int w,v;
    for(int i=0; i<n; i++){
        cin>>w>>v;
        products.push_back({{w,v},v/w});
    }

    cout<<"\nProducts are: "<<endl;
    for(auto i:products){
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    }
    cout<<endl;

    sort(products.begin(), products.end(),comp);

    cout<<"\nAfter sorting, Products are: "<<endl;
    for(auto i:products){
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    }

    cout<<endl;

    vector<int> bagProducts(n,0);
    int weight = 0;

    int count = 0;
    for(auto i: products){
        if(weight+i.first.first <=bag){
            weight+=i.first.first;
            bagProducts[count++] = i.first.first;
        }else{
            count++;
        }
        
    }

    cout<<"\nBag Products weight : ";
    for(int i:bagProducts){
        cout<<i<<" ";
    }
    cout<<endl;



}