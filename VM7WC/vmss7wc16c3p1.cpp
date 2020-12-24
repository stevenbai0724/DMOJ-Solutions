//https://dmoj.ca/problem/vmss7wc16c3p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int maxx = 0;
    int maxy = 0;
    int minx = 1e18;
    int miny = 1e18;

    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        maxx = max(maxx, x);
        maxy = max(maxy, y);
        minx = min(minx, x);
        miny = min(miny, y);
    }
    cout<<(maxx-minx)*(maxy-miny);
    return 0;
}