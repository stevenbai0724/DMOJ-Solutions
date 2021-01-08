//https://dmoj.ca/problem/ics4p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    sort(s.begin(), s.end());
    cout<<s<<"\n";
    while(next_permutation(s.begin(), s.end())){
        cout<<s<<"\n";
    }

    return 0;
}