//https://dmoj.ca/problem/dmopc15c2p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    double n, k;
    cin>>n>>k;
    int cuts = 0;
    int pieces = 1;

    while(pieces <k && pieces<n){
        pieces *= 2;
        cuts++;
    }
    cuts += ceil((n-pieces)/k);
    cout<<cuts;


    return 0;
}