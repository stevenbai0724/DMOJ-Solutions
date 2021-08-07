//https://dmoj.ca/problem/dmopc14c3p4
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n = 1e5;

    vector<int>factors(n+1);

    for(int i=1;i<=n;i++){
        factors[i]++;
        for(int j=2;j*i<=n;j++){
            factors[i*j]++;
        }
    }
    vector<vector<int>>arr(n+1);

    for(int i=1;i<=n;i++){
        arr[factors[i]].push_back(i);
    }
    int t; cin>>t;
    while(t--){
        int k, a, b;
        cin>>k>>a>>b;

        cout<<upper_bound(arr[k].begin(), arr[k].end(), b)-lower_bound(arr[k].begin(), arr[k].end(), a)<<"\n";

    }


    return 0;
}