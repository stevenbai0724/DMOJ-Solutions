//https://dmoj.ca/problem/bts18p4
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, nd;
int mx = 0, cnt = 0, ans = 0;
vector<int>colour;
vector<vector<int>>adj;
vector<int>dis;
vector<bool>vis;
vector<int>comp;

void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            dis[u] = dis[v] + 1;
            if(dis[u]>mx){
                nd = u;
                mx = dis[u];
            }
            dfs(u);
        }
    }
    colour[v] = 2;
}
void dfsComp(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u] ==0){
            dfsComp(u);
        }
    }
    colour[v] = 2;
}
void find_comp(){
    for(int i=1;i<=n;i++){
        if(vis[i] && colour[i]==0){
            comp[cnt]=i;
            dfsComp(i);
            cnt++;
        }
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    colour.resize(n+1);
    adj.resize(n+1);
    dis.resize(n+1);
    vis.resize(n+1);
    comp.resize(n+1);
    fill(vis.begin(), vis.end(), true);

    for(int i=1;i<=n;i++){
        int y;cin>>y;
        int x = (sqrt(y));
        if((x*x +x) !=y)vis[i] = false;
    }
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        if(!vis[x] || !vis[y])continue;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    find_comp();
    fill(colour.begin(), colour.end(), 0);

    for(auto x: comp){
        if(x==0)break;
        dfs(x);
        fill(colour.begin(), colour.end(), 0);
        fill(dis.begin(), dis.end(), 0);
        mx = 0;
        dfs(nd);
        ans = max(ans, mx+1);
        mx = 0;
    }

    cout<<ans;

    
    return 0;
}