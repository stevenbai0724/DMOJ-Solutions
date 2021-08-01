//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, d, q, l, t;
    cin>>n>>d>>q>>l>>t;

    n*=5;
    d*=10;
    q*=25;
    l*=100;
    t*=200;

    cout<<n+d+q+l+t<<"\n";



    return 0;
}