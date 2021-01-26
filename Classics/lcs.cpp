/https://dmoj.ca/problem/lcs
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >>n;
    int m; cin >>m;
    int ans = 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    vector<int>first(n+1);
    vector<int>second(m+1);

    for(int i = 1; i<=n; i++){
        int x; cin >> x;
        first[i] = x;
    }
    for(int i = 1; i<=m; i++){
        int x; cin >> x;
        second[i] = x;
    }
    
    for(int i =1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(first[i] == second[j]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout << ans<<endl;

    return 0;
}
