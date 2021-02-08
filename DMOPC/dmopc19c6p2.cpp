//https://dmoj.ca/problem/dmopc19c6p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b;
    cin>>a>>b;
    vector<int>aFreq(1e6+1);
    for(int i=2;i*i<=a;i++){
        while(!(a%i)){
            aFreq[i]++;
            a/=i;
        }
        
    }
    if(a>=2)aFreq[a]++;
    int ans = 1e18;
    for(int i=2;i<=1e6;i++){
        if(aFreq[i]!=0){
            int sum = 0;
            int p = 1;
            while(p<=b){
                p*=i;
                sum+=b/p;
            }
            ans = min(ans, sum/aFreq[i]);
        }
    }
    cout<<ans<<"\n";
    

    return 0;
}