//
#include <bits/stdc++.h>
using namespace std;
#define int long long
string s, t;
int n, m;
vector<vector<int>>dp;
vector<vector<bool>>vis;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>s>>t;
    n = s.length();
    m = t.length(); 

    dp.resize(n+1);
    vis.resize(n+1);
    for(int i=0;i<=n;i++){
        dp[i].resize(m+1);
        vis[i].resize(m+1);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1]==t[j-1]){
                dp[i][j] = max(dp[i][j], 1+dp[i-1][j-1]);
            }
        }
    }
    vector<char>ans;
    int cur = dp[n][m];
    int x = n;
    int y = m;
    while(cur!=0){
        if(dp[x-1][y]!=cur && dp[x][y-1]!=cur){
            ans.push_back(s[x-1]);
            x--; y--;
            cur--;
        }
        else if(dp[x-1][y]==cur){
            x--;
        }
        else if(dp[x][y-1]==cur){
            y--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto c: ans){
        cout<<c;
    }



}