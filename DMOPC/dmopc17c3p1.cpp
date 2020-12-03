//https://dmoj.ca/problem/dmopc17c3p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int ans = 1000000000000;
    for(int i =0; i<n; i++){
        int x; cin>>x;
        ans = min(ans, x);
    }
    cout<<ans;


    return 0;
}