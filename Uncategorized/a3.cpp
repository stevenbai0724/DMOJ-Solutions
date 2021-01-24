//https://dmoj.ca/problem/a3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>nums;

    for(int i=192;i<20000;i++){
        if((i*i*i)%1000 == 888)nums.push_back(i);
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<*lower_bound(nums.begin(), nums.end(), n)<<"\n";
    }


    return 0;

}
