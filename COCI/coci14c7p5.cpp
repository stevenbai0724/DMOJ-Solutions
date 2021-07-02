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
vector<double>arr;
int n, k;
bool good(double mid){
    vector<double>temp = arr;
    vector<double>mn(n+1);
    vector<double>psa(n+1);
    double mnn = 1e18;
    double sum = 0;
    for(int i=1;i<=n;i++){
        temp[i]-=mid;
        sum += temp[i];
        psa[i] = sum;

    }
    for(int i=1;i<=n;i++){
        mnn = min(mnn, psa[i]);
        mn[i] = mnn;
    }
    for(int i=k;i<=n;i++){
        if(psa[i]-mn[i-k]>=0)return true;
    }
    return false;
    
}


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>k;
    arr.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int t = 70;
    double low = 0;
    double hi = 1e6+2;
    
    while(t--){
        double mid = (low+hi)/2.0;
    
        if(good(mid))low = mid;
        else hi = mid;
    }

    cout<<fixed<<setprecision(20)<<low<<"\n";


    

    return 0;
}