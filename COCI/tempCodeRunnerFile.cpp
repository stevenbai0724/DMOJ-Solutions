//https://dmoj.ca/problem/coci14c7p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int>price(n+1);
    for(int i=1;i<=n;i++){
        cin>>price[i];
    }

    int x; cin>>x;
    vector<int>menu(4);
    for(int i=0;i<4;i++){
        cin>>menu[i];
    }

    int t; cin>>t;
    vector<int>freq(n+1);
    for(int i=1;i<=t;i++){
        int y; cin>>y;
        freq[y]++;
    }

    int ans = 0;
    int mn = 1e18;
    int raw = 0;
    int save = 0;
    for(int i=0;i<4;i++){
        int cur = menu[i];
        if(freq[cur]){
            mn = min(mn, freq[cur]);
            raw += price[cur]*freq[cur];
        }
    }
    if(mn!=1e18){
        save = mn*x;
        if(save<=raw){
            ans = save;
            for(int i=0;i<4;i++){
                int cur = menu[i];
                if(freq[cur]){
                    freq[cur]-=mn;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans+= freq[i]*price[i];
    }
    cout<<ans<<"\n";

    return 0;
}