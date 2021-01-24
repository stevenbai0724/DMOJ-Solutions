//https://dmoj.ca/problem/dpa
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>arr;
vector<int>dp;
vector<int>vis;
int frog(int x){
    if(x ==1)return 0;
    else if(x==2)return abs(arr[x]-arr[x-1]);
    else if(vis[x])return dp[x];
    else {
        dp[x] =min(frog(x-1)+abs(arr[x]-arr[x-1]), frog(x-2)+abs(arr[x]-arr[x-2]));
        vis[x] = true;
        return dp[x];
    }   
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    arr.resize(n+1);
    dp.resize(n+1);
    vis.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<frog(n);
    
    return 0;
}