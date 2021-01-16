//https://dmoj.ca/problem/nccc3s4
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;cin>>n;
    int mx = 0, sum = 0;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        sum+=x;
        mx = max(mx, x);
    }
    if(mx> sum-mx || (mx%2==1))cout<<"NO\n";
    else cout<<"YES\n";
    
    return 0;
}