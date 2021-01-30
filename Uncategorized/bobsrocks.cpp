//https://dmoj.ca/problem/bobsrocks
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>freq(51);
    int ans = 0;
    int rock = 0;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        freq[x]++;
        if(freq[x]*x >= ans){
            rock = x;
            ans = freq[x]*x;
        }
    }
    cout<<rock<<"\n";

    return 0;
 
}