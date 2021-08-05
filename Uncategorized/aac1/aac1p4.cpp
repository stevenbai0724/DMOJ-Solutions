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
    
    int n, q;
    cin>>n>>q;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        
        for(int i=l;i<=r;i++){
            for(int j=l;j<=r;j++){
                if(arr[i]==arr[j])continue;
                if(arr[i]*arr[j]==x){
                    cout<<"YES\n";
                    goto nxt;
                }
            }
        }

        cout<<"NO\n";
        nxt:;

    }


    return 0;
}