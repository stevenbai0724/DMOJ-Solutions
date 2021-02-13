//https://dmoj.ca/problem/bts17p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define string std::string
int n, m, k;
vector<int>arr;

bool good(int check){
    vector<int>pos;
    pos.push_back(0);
    for(int i=1;i<=n;i++){
        if(arr[i]<=check && arr[i]!=0)pos.push_back(i);
    }
    pos.push_back(n+1);
    int sz = pos.size();
    for(int i=1;i<sz;i++){
        if(pos[i]-pos[i-1]>k)return false;
    }
    return true;

}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m>>k;   
    arr.resize(n+1);
    
    if(n==0){
        cout<<0<<"\n";
        return 0;
    }
    
    while(m--){
        int p,t;
        cin>>p>>t;
        arr[p] = t;
    }
    int l = -1;
    int r = 1e18;

    while(l+1<r){
        int m = (l+r)/2;
        if(good(m))r = m;
        else l = m;
    }
    if(r==1e18)cout<<-1<<"\n";
    else cout<<r<<"\n";


    return 0;
}