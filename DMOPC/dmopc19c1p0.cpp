//https://dmoj.ca/problem/dmopc19c1p0
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x; cin >> x;
    int low = 1000000000;
    int high = 0; 
    for(int i = 0 ; i<x; i++){
        int n; cin>>n;
        high = max(high, n);
        low = min(low ,n);
    }
    cout << (high-low) << endl;

    return 0;
}