//https://dmoj.ca/problem/utso21p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>ans(1e6+1);
    int cnt = 2;
    for(int i=2;i<=1e6;i++){
        if(i&1){
            ans[i]=((i/2+1)*(i+1));
        }
        else{
            ans[i]=(i*cnt+1);
            cnt++;
        }
    }

    int n; cin>>n;
    if(n==2){
        cout<<1<<"\n";
        return 0;
    }
    for(int i=2;i<=1e6;i++){
        if(ans[i]>=n){
            cout<<i<<"\n";
            return 0;
        }
    }

    return 0;
}