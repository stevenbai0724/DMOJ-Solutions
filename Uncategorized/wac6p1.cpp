//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    for(int i=1;i<=n;i++){
        double p, c;
        cin>>p>>c;
        cout<<setprecision(20)<<fixed<<p/(c/100.0 +1)<<"\n";
    }
    
    return 0;

}