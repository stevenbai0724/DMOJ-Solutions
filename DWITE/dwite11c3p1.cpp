//https://dmoj.ca/problem/dwite11c3p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 5;
    while(t--){
        int n; cin>>n;
        int d = 1e18;
        int w = -1e18;
        string ans = "";

        for(int i=0;i<4;i++){
            string s; cin>>s;
            int x; cin>>x;
            if(abs(x-n)<=d){
                if(x>w){
                    w = x;
                    d = abs(x-n);
                    ans = s;
                }
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}