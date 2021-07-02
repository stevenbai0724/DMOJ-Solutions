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
    
    int n; cin>>n;
    vector<int>arr(2*(n+1));

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i+n] = arr[i];
    }
    vector<int>psa(2*(n+1));
    int sum = 0;
    for(int i=1;i<=2*n;i++){
        sum += arr[i];
        psa[i] = sum;
    }

    for(int i=1;i<=n;i++){
        int mn = 1e18;
        for(int j=i;j<i+n;j++){
            int lower = psa[j]-psa[i-1];
            int higher = psa[i+n-1]-psa[j];

            mn = min(mn, abs(lower-higher));
        }
        cout<<mn;
        if(i<n)cout<<" ";
    }
    cout<<"\n";


    

    return 0;
}