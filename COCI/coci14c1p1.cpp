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
    vector<int>arr(n+1);
    int sum = 0;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(i==1){
            arr[i] = x;
            sum+=arr[i];
            continue;
        }
        int total = i*x;
        arr[i] = total-sum;
        sum+=arr[i];

    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
 
    return 0;
}