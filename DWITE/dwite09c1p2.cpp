//https://dmoj.ca/problem/dwite09c1p2
#include <bits/stdc++.h>
using namespace std;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 5;
    while(t--){
        string s; cin>>s;

        cout<<s<<"\n";
        while(next_permutation(s.begin(), s.end())){
            cout<<s<<"\n";
        }
    }
    return 0;
}