//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;

    vector<vector<int>>arr(2, vector<int>(n+1));
    vector<bool>useFrench(n+1);
    vector<int>dp(n+1);

    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }

    dp[1] = max(arr[0][1], arr[1][1]);
    dp[2] = max(arr[0][2], arr[1][2]) + dp[1];

    if(arr[0][1]>arr[1][1])useFrench[1] = true;
    if(arr[0][2]>arr[1][2])useFrench[2] = true;

    for(int i=3;i<=n;i++){
        if(useFrench[i-1] && useFrench[i-2]){
            int case1 = dp[i-1] + arr[1][i]; //take english
            int case2 = arr[0][i] + dp[i-1] + (arr[1][i-1]-arr[0][i-1]); //i-1 is english, take french
            int case3 = arr[0][i] + dp[i-1] + (arr[1][i-2]-arr[0][i-2]); //i-2 is english, take french
            
            int mx = max(case1, max(case2, case3));
            
            if(mx==case1){
                useFrench[i] = false;

            }
            else if(mx==case2){
                useFrench[i-1] = false;
                useFrench[i] = true;
            }
            else{
                useFrench[i-2] = false;
                useFrench[i] = true;
            }
            dp[i] = mx;


        }
        else{
            int mx = (arr[0][i], arr[1][i]);
            if(mx==arr[0][i]){
                useFrench[i] = true;
            }
            else{
                useFrench[i] = false;
            }
            dp[i] = dp[i-1] + mx;
        }
    }
    cout<<dp[n]<<"\n";




    return 0;
}