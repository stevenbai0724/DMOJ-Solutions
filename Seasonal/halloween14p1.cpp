//https://dmoj.ca/problem/halloween14p1
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    if(n<=k) cout<<k-n;
    else  cout<<min(n%k, k-(n%k));

    return 0;
}