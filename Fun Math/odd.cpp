//https://dmoj.ca/problem/odd
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x; cin>>x;
    int val = 0;
    for(int i =0; i<x; i++){
        int n; cin>>n;
        val ^=n;
    }
    cout<<val<<"\n";

    return 0;
}