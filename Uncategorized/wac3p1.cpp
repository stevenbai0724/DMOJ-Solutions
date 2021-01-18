//https://dmoj.ca/problem/wac3p1
#include <bits/stdc++.h>
using namespace std;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t,d,p;
    cin>>t>>d>>p;
    int count=(t<-40)+ (d>=15) + (p>50);
    if(count>=2) cout<<"YES";
    else cout<<"NO";
    return 0;
}