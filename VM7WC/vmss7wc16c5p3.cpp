//https://dmoj.ca/problem/vmss7wc16c5p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, nd;
vector<int>dis;
vector<vector<int>>adj;
vector<int>colour;
int mx = 0;
void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            dis[u] = dis[v]+1;
            if(dis[u]>mx){
                mx = dis[u];
                nd = u;
            }
            dfs(u);
        }
            
    }
    colour[v] = 2;
}
    
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    dis.resize(n+1);
    adj.resize(n+1);
    colour.resize(n+1);

    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);

    fill(colour.begin(), colour.end(), 0);
    fill(dis.begin(), dis.end(), 0);
    mx = 0;
    dfs(nd);
    cout<<mx;
    
    return 0;
}
