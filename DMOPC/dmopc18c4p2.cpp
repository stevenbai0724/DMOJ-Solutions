//https://dmoj.ca/problem/dmopc18c4p2
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    
    int n; cin>>n;
    vector<int>arr(n+1);
    int sum = 0;
    int ans = 999999999;
    for(int i =1;i<=n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    vector<bool>dp(sum+1);

    for(int i =1;i<=n;i++){
        dp[arr[i]] = true;
    }

    for(int i =1;i<=sum;i++){
        for(int j = 1;j<=n;j++){
            if(i>=arr[j] && dp[i-arr[j]] ){
                dp[i] = true;
            }
        }
    }
    for(int i=1;i<=sum;i++){
        if(dp[i]) ans = min(ans, abs(i-(sum-i)));
    }

    if(sum!=0)cout<<ans;
    else cout<<0;
    


    return 0;
}