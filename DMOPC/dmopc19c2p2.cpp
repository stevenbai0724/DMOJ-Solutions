//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<int>>arr(n+1, vector<int>(m+1));
    vector<vector<int>>dp(n+1, vector<int>(m+1));


    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 1e18;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            
        }   
    }
    dp[1][1] = arr[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1)continue;
            dp[i][j] = arr[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<"\n";


    return 0;
}