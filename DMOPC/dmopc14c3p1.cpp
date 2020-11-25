//https://dmoj.ca/problem/dmopc14c3p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k, d;
    cin >>n >>k >>d;
    int ans = n*(pow(k, d));

    cout<<ans;

    return 0;
}