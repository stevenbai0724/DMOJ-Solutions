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
    
    int x, n;
    cin>>x>>n;

    int ans = x*(n+1);

    for(int i=1;i<=n;i++){
        int y;
        cin>>y;
        ans-=y;
    }
    cout<<ans<<"\n";
    

    return 0;
}