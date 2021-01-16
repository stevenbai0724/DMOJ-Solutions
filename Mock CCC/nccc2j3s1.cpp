//https://dmoj.ca/problem/nccc2j3s1
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
    cout<<min(sum-mx, (int)sum/2);
    
    return 0;
}