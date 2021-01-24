//https://dmoj.ca/problem/dpc
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>>dp;
vector<vector<int>>arr;
vector<vector<bool>>vis;
int f(pair<int,int>p){
    int x = p.first;
    int y = p.second;
    if(x==1){
        return arr[1][y];
    }
    else if(vis[x][y])return dp[x][y];
    else{   
        int mx = 0;
        for(int i=1;i<=3;i++){
            if(i==y)continue;
            mx = max(mx, f({x-1, i}));
        }
        dp[x][y] = arr[x][y]+mx;
        vis[x][y] = true;
        return dp[x][y];
    }
    
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    dp.resize(n+1);
    arr.resize(n+1);
    vis.resize(n+1);

    for(int i=1;i<=n;i++){
        dp[i].resize(4);
        arr[i].resize(4);
        vis[i].resize(4);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>arr[i][j];
        }
    }
    cout<<max(f({n,1}), max(f({n,2}), f({n,3})));

    return 0;
}