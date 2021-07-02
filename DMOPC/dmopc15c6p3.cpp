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
    
    int n, m, k;
    cin>>n>>m>>k;

    vector<int>arr(n+2);
    vector<int>psa(n+1);
    vector<int>temp;
    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        arr[a]--;
        arr[b+1]++;
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=arr[i];
        psa[i] = sum + m;
    }
    temp = psa;
    sum = 0;
    for(int i=1;i<=n;i++){
        sum+=temp[i];
        psa[i] = sum;
    }
    if(k==0){
        cout<<0<<"\n";
        return 0;
    }
    if(n==1){
        if(psa[1]<k){
            cout<<-1<<"\n";
        }
        else cout<<1<<"\n";
        return 0;
    }
    int l = 1, r = 2;

    int mn = 1e9;
    psa[0] = 0;
    while(r<=n){
        int cur = psa[r]-psa[l-1];
        if(cur<k){
            r++;
        }
        else{
            mn = min(mn, r-l+1);
            l++;
        }
    }
    if(mn!=1e9)cout<<mn<<"\n";
    else cout<<-1<<"\n";


    return 0;
}