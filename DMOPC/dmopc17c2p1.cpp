#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin>>n;
    int ans =0;

    for(int i=1;i<=n;i++){
        int c,v;cin>>c>>v;
        if(v>0)ans+=c;
    }
    cout<<ans;


    return 0;
}