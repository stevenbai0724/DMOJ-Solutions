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

    vector<string>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=1;i<(1<<n);i++){
        vector<string>temp;
        vector<bool>vis(26);

        for(int j=0;j<n;j++){
            if((1<<j)&i){
                temp.push_back(arr[j]);
            }
        }
        for(auto s: temp){
            for(auto c: s){
                vis[(int)c-97] = true;
            }
        }
        if(count(vis.begin(), vis.end(), true)==26)ans++;

    }
    cout<<ans<<"\n";
    return 0;
}