//https://dmoj.ca/problem/dmopc14c7p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>tri(45001);
    vector<int>sum(45001);

    for(int i=1;i<=45000;i++){
        tri[i] = (i)*(i+1)/2;
    }
    sum[1] = 1;
    for(int i=2;i<=45000;i++){
        int x = ((tri[i-1]+1)+(tri[i]))*i/2;
        sum[i] = x;
    }
    int ans; cin>>ans;
    auto it = lower_bound(tri.begin(), tri.end(), ans);
    int ind = it-tri.begin();
    cout<<sum[ind]<<"\n";
    return 0;
}