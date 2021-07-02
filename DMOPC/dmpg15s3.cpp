//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ans+=arr[i];
    }

    int q; cin>>q;
    while(q--){
        int a, b; 
        cin>>a>>b;
        ans -= min(arr[a], min(arr[a+1], b));
    }
    cout<<ans<<"\n";

    return 0;
}