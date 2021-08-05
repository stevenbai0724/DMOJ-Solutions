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
    string s; cin>>s;
    vector<int>freq(26);
    for(auto c: s){
        freq[c-97]++;
    }
    int singles = 0;
    for(int i=0;i<26;i++){
        singles += freq[i]%2;
    }
    if(singles==0){
        cout<<1<<"\n";
        return 0;
    }
    cout<<singles<<"\n";

    return 0;
}