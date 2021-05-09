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

    int t = 5;
    while(t--){
        int n; cin>>n;
        double ans = 0;

        if(n<=3){
            cout<<"The length of "<< n<< "! is "<<floor(1)<<"\n";
            continue;
        }
        for(int i=2;i<=n;i++){
            ans+= log10(i);

        }
        cout<<"The length of "<< n<< "! is "<<floor(ans+1)<<"\n";

    }

    return 0;
}
