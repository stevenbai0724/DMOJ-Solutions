//https://dmoj.ca/problem/coci06c2p4
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; 
    int d = 0;
    for(int i =2;i<=n-2;i++){
        d+= (i-1)*(n-1-i);
    }
    cout<<d*n/4;
}
