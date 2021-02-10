//https://dmoj.ca/problem/mnyc17p3
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

    if(s==t){
        cout<<s<<"\n";
        return 0;
    }
    vector<int>hashes1(n+1);
    vector<int>hashes2(m+1);
    vector<int>power(max(n, m)+1);
    int base = 131;
    power[0] =1;
    for(int i=1;i<=max(m,n);i++){
        power[i] = power[i-1]*base;
        power[i]%=mod;
    }
    for(int i=1;i<=n;i++){
        hashes1[i] = hashes1[i-1]*base + s[i-1];
        hashes1[i]%=mod;
    }
    for(int i=1;i<=m;i++){
        hashes2[i] = hashes2[i-1]*base + t[i-1];
        hashes2[i]%=mod;
    }
    bool found = false;
    int mn = min(n,m);
    int ind = 0;
    for(int i=1;i<=mn;i++){
        int hsh1 = hashes1[n] - (hashes1[n-i]*power[i])%mod;
        hsh1+=mod;
        hsh1%=mod;
        int hsh2 = hashes2[i]%mod;


        if(hsh1==hsh2){
            ind = i;
        }
    
    }
    string ans = s;
    for(int i=ind;i<m;i++){
        ans+=t[i];
    }
    cout<<ans<<"\n";

    return 0;
}