//https://dmoj.ca/problem/cchange
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x, n; //sum, denominations  
    cin>>x>>n;

    vector<int>coins(n+1);
    vector<int>dp(x+1, 1e9); //d[i] num of coins to make a sum of i coins
    for(int i=1;i<=n;i++){
        cin>>coins[i];
        dp[coins[i]] = 1;
    }
    sort(coins.begin(), coins.end());

    for(int i=1;i<=x;i++){
        for(int j = 1;j<=n;j++){
            if(i>=coins[j] && dp[i]!=1 && dp[i-coins[j]]!=0){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    cout<<dp[x];
    return 0;
}