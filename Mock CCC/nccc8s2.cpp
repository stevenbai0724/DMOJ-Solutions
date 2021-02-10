//https://dmoj.ca/problem/nccc8s2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define string std::string

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    int mod = 1e9+7;
    vector<int>freq(26);
    int ans = 1;
    for(int i=0;i<s.length();i++){
        freq[(int)s[i]-97]++;

    }
    for(int i=0;i<26;i++){
        ans*=freq[i]+1;
        ans%=mod;
    }
    cout<<ans<<"\n";

    return 0;
}