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

    int n, q;
    cin>>n>>q;

    vector<int>arr(n+1);
    vector<int>rmi(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int lastAns = 0;

    for(int i=1;i<=n;i++){
        int cnt = 0;
        set<int>s;
        for(int j=i;j<=n;j++){
            cnt++;
            s.insert(arr[j]);
            if(s.size()!=cnt)break;
        }
        rmi[i] = s.size() + i - 1;
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        l ^= lastAns;
        r ^= lastAns;
        int mx = 1;

        for(int i=1;i<=n;i++){
            if(i<=l && rmi[i]>=r)mx = max(mx, rmi[i]-i+1);
        }
        lastAns = mx;
        cout<<mx<<"\n";
    }

    
    return 0;
}