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
    vector<int>arr(n);

    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr.begin(), arr.end());
    if(n==2 && sum&1){
        cout<<1<<"\n";
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int cur = arr[i];
        for(int j=i+1;j<n;j++){
            int nxt = arr[j];
            if((cur+nxt)&1)continue;
            int avg = (cur+nxt)/2;
            if(*lower_bound(arr.begin(), arr.end(), avg)==avg){
                cout<<3<<"\n";
                return 0;
            }
        }
    }
    cout<<2<<"\n";




    return 0;
}