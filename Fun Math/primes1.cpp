//https://dmoj.ca/problem/primes1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<bool>prime(1001, true);
    
    for(int i=2;i*i<=1000;i++){
        if(prime[i]){
            for(int j=2;j*i<=1000;j++){
                prime[i*j] = false;
            }
        }
    }
    int n; cin>>n;
    for(int i=2;i<=1000;i++){
        if(n==0)break;
        if(prime[i]){
            cout<<i<<"\n";
            n--;
        }
    }
    return 0;
}
