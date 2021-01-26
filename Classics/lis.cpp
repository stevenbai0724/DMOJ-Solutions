//https://dmoj.ca/problem/lis
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
   
    int n; cin>>n;
    vector<int>val(1e6+5, 1e18);
    val[0] = 0;
    int ans = 0;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        int index = lower_bound(val.begin(), val.end(), x) - val.begin();
        val[index] = x;
    }
    for(int i=1;i<=n;i++){
        if(val[i]!=1e18){
            ans++;
        }
        else break;
    }
    cout<<ans<<"\n";
   
    return 0;

}