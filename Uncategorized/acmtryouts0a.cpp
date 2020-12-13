//https://dmoj.ca/problem/acmtryouts0a
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin >>t;
    

    for(int i = 0; i<t; i++){
        int n; cin>>n;
        int ans = 0;
        for(int j = 0; j<n; j++){
            int f; cin>>f;

            ans = max(ans, f);

        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
