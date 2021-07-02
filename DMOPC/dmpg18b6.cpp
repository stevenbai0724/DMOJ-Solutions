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

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    int ans = 1;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());

    
    int cur = arr[0];
    for(int i=1;i<n;i++){
        
        if(cur-arr[i]>=k){
            ans++;
            cur = arr[i];
        }

    }
    cout<<ans<<"\n";

    return 0;
}