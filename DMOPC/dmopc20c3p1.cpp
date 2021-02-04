//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    set<int>s;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        s.insert(x);
    }
    if(s.size()==n)cout<<"YES\n";
    else cout<<"NO\n";
 
}