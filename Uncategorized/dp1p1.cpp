//https://dmoj.ca/problem/dp1p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n; 
vector<int>arr;
vector<int>dp;
vector<int>vis;

int sum(int x){
    if(x==1)return arr[1];
    else if(x==2)return arr[2];
    else if (vis[x])return dp[x];
    else{
        dp[x] = max(sum(x-2)+arr[x], sum(x-1));
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
    cout<<sum(n);
    
    return 0;
}