//https://dmoj.ca/problem/dpb
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<int>arr;
vector<int>dp;
vector<int>vis;
int frog(int x){
    if(x==1) return 0;
    if(vis[x])return dp[x];
    else{
        int mn = 1e18;
        for(int i=1;i<=k;i++){
            
            if(x-i<1)break;
            mn = min(mn,abs(arr[x]-arr[x-i])+ frog(x-i));
        }
        dp[x] = mn;
        vis[x] = true;
        return dp[x];
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>k;
    arr.resize(n+1);
    dp.resize(n+1);
    vis.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<frog(n)<<"\n";
    
    return 0;
}