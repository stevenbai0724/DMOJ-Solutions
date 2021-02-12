//https://dmoj.ca/problem/coci14c4p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
vector<double>flow;
vector<bool>super;
vector<vector<int>>adj;
vector<int>leaf;
vector<double>water;
int n;

void dfs(int v){
    for(auto u:adj[v]){
        
        water[u] = water[v] * flow[u];
        if(super[u])water[u]*=water[u];
        dfs(u);
    }
}
void reset(){
    fill(water.begin(), water.end(), 0);
}
bool good(double check){
    check/=1000.0;

    water[1] = check;
    
    dfs(1);

    for(int i=1;i<=n;i++){
        if(leaf[i]==-1)continue;
        if(water[i]<leaf[i])return false;
    }
    return true;

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    flow.resize(n+1);
    super.resize(n+1);
    adj.resize(n+1);
    leaf.resize(n+1);
    water.resize(n+1);
    flow[1] = 1;
    for(int i=1;i<n;i++){
        int x,y,w,s;
        cin>>x>>y>>w>>s;
        double weight = w/100.0;
        adj[x].push_back(y);
        flow[y] = weight;
        super[y] = s;
    }
    for(int i=1;i<=n;i++){
        cin>>leaf[i];
    }
    
    int l = 0;
    int r = 1e18;

    while(l+1<r){
        int m = (l+r)/2;
        reset();
        if(good(m))r = m;
        else l = m;  
    }
    cout<<setprecision(20)<<fixed<<r/1000.0<<"\n";

    return 0;
}