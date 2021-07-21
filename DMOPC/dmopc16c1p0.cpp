//https://dmoj.ca/problem/dmopc16c1p0
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
    
    int w, c;
    cin>>w>>c;

    string ans;

    if(w==3 && c>=95){
        ans = "absolutely";
    }
    else if (w==1 && c<=50){
        ans = "fairly";
    }
    else ans = "very";

    cout<<"C.C. is "<<ans<<" satisfied with her pizza.\n";
    

    return 0;
}