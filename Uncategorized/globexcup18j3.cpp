//https://dmoj.ca/problem/globexcup18j3
#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum(int k){
    int s = 0;
    while(k>0){
        s += k%10;
        k/=10;
    }
    return s;
}
bool prime(int k){
    if(k==1)return false;
    for(int i=2;i*i<=k;i++){
        if(k%i==0)return false;
    }
    return true;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int ans = 0;
    while(n--){
        int k; cin>>k;

        cout<<"sum"<<sum(k)<<"\n";
        if(prime(k) && prime(sum(k)))ans++;
    }
    cout<<ans<<"\n";
    return 0;

}