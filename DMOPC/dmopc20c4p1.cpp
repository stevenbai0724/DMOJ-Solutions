//dmopc20c4p1
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n, s;
        cin>>n>>s;

        int total = (n)*(n+1)/2;

        int target = total-s;

        int lo, hi;

        if(target&1){
            lo = target/2;
            hi = lo+1;
        }
        else{
            lo = target/2 - 1;
            hi = lo + 2;
        }
        int case1 = lo;
        int case2 = target/2;
        int case3 = n-hi+1;
        cout<<min(case1, min(case2, case3))<<"\n";
    }


    return 0;
}