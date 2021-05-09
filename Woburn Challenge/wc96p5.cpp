//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
vector<vector<int>>arr;
vector<vector<int>>vis;
vector<vector<int>>dp;
int n, m;
int solve(int x, int y){

    if(vis[x][y]){
        return dp[x][y];
    }
    vis[x][y] = true;
    if(x==1 && y==m){
        dp[x][y] = arr[x][y];
       
    }
    else if(x==1){
        dp[x][y] = arr[x][y] + solve(x, y+1);
    }
    else if(y==m){
        dp[x][y] = arr[x][y] + solve(x-1, y);
    }
    else {
        dp[x][y] = arr[x][y] + max(solve(x-1,y), solve(x, y+1));
    }

    return dp[x][y];

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;

    arr.resize(n+1);
    vis.resize(n+1);
    dp.resize(n+1);
    for(int i=0;i<=n;i++){
        arr[i].resize(m+1);
        vis[i].resize(m+1);
        dp[i].resize(m+1);
    }

    while(true){
        int a, b;
        cin>>a>>b;
        if(a==0 && b==0)break;
        
        arr[n-a+1][b] = 1;

    }

    cout<<solve(n, 1)<<"\n";


    return 0;
}