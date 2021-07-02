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
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>>ind(m+1);
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ind[arr[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        ind[i].push_back(1e9);
    }
    int q; cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        int len = r-l+1;
        gp_hash_table<int, bool>mp;
        int cnt = 0;
        for(int t = 0; t<50; t++){
            int checkInd = rng()%len + l;
            int flavour = arr[checkInd];
            auto it1 = upper_bound(ind[flavour].begin(), ind[flavour].end(), r);
            auto it2 = lower_bound(ind[flavour].begin(), ind[flavour].end(), l);

            if(it1-it2 >= (2*len/3.0)){
                cnt = 2;
                break;

            }
            if(it1-it2>= (len/3.0) && !mp[flavour]){
                mp[flavour] = true;
                cnt++;
            }

        }
        if(cnt>=2)cout<<"YES\n";
        else cout<<"NO\n";


    }
  

    return 0;
}