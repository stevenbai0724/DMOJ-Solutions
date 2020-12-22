//https://dmoj.ca/problem/dmopc18c2p4
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<int>arr(n+1);
    vector<int>psa(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int sum =0;
    for(int i=1;i<=n;i++){
        sum+=arr[i];
        psa[i] = sum;
    }

    int l,r;
    l = 1;
    r = 1;
    int ans = 1e18;
    while(r<=n ){   
        int s = psa[r]-psa[l-1];
        if(s<m)r++;
        if(s>=m){
            ans = min(ans, abs(r-l+1));
            l++;
        }
    }
    if(ans!=1e18)cout<<ans;
    else cout<<-1;


    return 0;
}