//https://dmoj.ca/problem/dmopc15c3p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int>colour;
vector<int>parent;
vector<vector<int>>adj;
vector<int>dis;
bool found = false;
bool dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u] == 0){
            parent[u] = v;
            dis[u] = dis[v] + 1;
            dfs(u);
        }
        else if(colour[u]==1){
            if(dis[v]-dis[u]==5)found = true;
        }
    }
    colour[v] = 2;
    return found;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(n+1);
    colour.resize(n+1);
    dis.resize(n+1);
    parent.resize(n+1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(dfs(i)){
            cout<<"YES\n";
            return 0;
        }
        fill(dis.begin(), dis.end(), 0);
        fill(colour.begin(), colour.end(), 0);
        fill(parent.begin(), parent.end(), 0);
    }
    cout<<"NO\n";




}