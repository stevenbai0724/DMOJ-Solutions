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

    int h, m;
    cin>>h>>m;

    m-=45;

    if(m>=0){
        cout<<h<<" "<<m<<"\n";
        return 0;
    }
    h--;
    m += 60;

    if(h==-1)h = 23;
    cout<<h<<" "<<m<<"\n";

    return 0;
}