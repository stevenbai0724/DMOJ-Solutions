//https://dmoj.ca/problem/bf4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s, t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    int base = 131;
    vector<int>power(n+1); power[0] = 1;
    vector<int>hashes1(n+1);
    int hashes2 = 0;
    for(int i=1;i<=n;i++){
        hashes1[i] = hashes1[i-1]*base + s[i-1];
        hashes1[i]%=mod;
        power[i] = power[i-1] * base;
        power[i]%=mod;
    }
    for(int i=0;i<m;i++){
        hashes2*=base;
        hashes2%=mod;
        hashes2+=t[i];
        hashes2%=mod;
    }
    for(int i=m;i<=n;i++){
        int hsh = hashes1[i] - (hashes1[i-m] * power[m])%mod;
        hsh+=mod;
        hsh%=mod;
        if(hsh==hashes2){
            cout<<i-m<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";



    return 0;
}