//https://dmoj.ca/problem/dmopc14c5p2
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int ans = 0;
    for(int i = 0 ;i<n; i++){
        int x, y;
        cin>>x>>y;
        ans = max(ans, y-x);
    }
    cout<<ans;

    return 0;
}