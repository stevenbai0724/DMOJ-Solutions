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
    
        string s, t;
        cin>>s>>t;

        int n = s.length();
        int m = t.length();
        int ind = 0;
        for(int i=0;i<min(n,m);i++){
            if(s[i]!=t[i]){
                ind = i;
                break;
            }
            if(i+1 ==min(n,m)){
                ind = i+1;
            }
        }

        int ans = 0;

        ans += abs(n-ind);

        ans += abs(m-ind);



        cout<<ans<<"\n";
  

    return 0;
}