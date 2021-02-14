//https://dmoj.ca/problem/dmopc16c1p3//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<double>arr(n+1);
    vector<double>dp(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    dp[1] = arr[1];


    for(int i=2;i<=n;i++){
        double a = arr[i] + dp[i-1];
        double b = dp[i-2] + min(arr[i],arr[i-1])/2.0 + max(arr[i],arr[i-1]);
        double c = 1e18;

        if(i>2){
            c = arr[i]+arr[i-1]+arr[i-2] - min(arr[i], min(arr[i-1], arr[i-2])) + dp[i-3];
        }
        dp[i] = min(a, min(b,c));

    }
    cout<<setprecision(1)<<fixed<<dp[n]<<"\n";


    return 0;
}