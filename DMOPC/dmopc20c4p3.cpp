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

    vector<pair<int, int>>roomba;
    
    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        roomba.push_back({x,y});
    }
    int ans = 0;
    while(m--){
        int x, y;
        cin>>x>>y;
        
        for(auto p: roomba){
            int newx = p.first;
            int newy = p.second;

            if(newy<=y && newx>=x)ans++;
        }
    }
    cout<<ans<<"\n";

 

    return 0;
}