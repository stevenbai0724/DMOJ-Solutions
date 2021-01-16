//https://dmoj.ca/problem/nccc5j5s3
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<int>colour;
vector<vector<int>>adj;
vector<pair<int, int>>r;
int curx, cury;

void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(v==curx && u==cury)continue;
        if(colour[u]==0)dfs(u);
    }
    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;    
    colour.resize(n+1);
    adj.resize(n+1);
    r.resize(m+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        r[i] = {x,y};
    }
    for(int i=1;i<=m;i++){
        curx = r[i].first;
        cury = r[i].second;
        fill(colour.begin(), colour.end(), 0);
        dfs(1);
        if(colour[n]==2)cout<<"YES\n";
        else cout<<"NO\n";
    }    
    return 0;
}