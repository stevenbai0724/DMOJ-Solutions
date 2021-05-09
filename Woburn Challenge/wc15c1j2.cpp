//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;

    if(n%m==0){
        cout<<m<<" group(s) of "<<n/m<<"\n";
        return 0;
    }
    int bottom = n/m;
    int top = n/m + 1;
    int groupA = 0;
    int groupB = 0;

    groupA = (m)*(top) - n;

    groupB = (n - (groupA)*(bottom))/top;


    cout<<groupA<<" group(s) of "<<bottom<<"\n";
    cout<<groupB<<" group(s) of "<<top<<"\n";   

    return 0;
}