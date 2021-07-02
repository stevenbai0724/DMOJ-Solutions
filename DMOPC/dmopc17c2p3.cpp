//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
int n, r, x, y;
vector<vector<int>>adj;
vector<int>colour;
vector<bool>rabbit;
vector<int>parent;
vector<int>banned;
void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            parent[u] = v;
            dfs(u);
        }
    }
    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>r;
    adj.resize(n+1);
    colour.resize(n+1);
    parent.reserve(n+1);
    banned.resize(n+1);
    rabbit.resize(n+1);

    for(int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=r;i++){
        int x; cin>>x;
        rabbit[x] = true;
    }
    cin>>x>>y;

    dfs(x);

    vector<int>path;
    path.push_back(y);
    int cur = y;
    while(cur!=x){
        cur = parent[cur];
        path.push_back(cur);
        banned[cur] = true;
    }
    reverse(path.begin(), path.end());
    int ans = 1e9;
    for(int cur: path){
        if(rabbit[cur]){
            ans = 0;
            break;
        }
        queue<int>q;
        vector<int>dis(n+1);
        vector<int>vis(n+1);

        q.push(cur);
        vis[cur] = true;

        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int u: adj[v]){
                if(banned[v]&&banned[u])continue;
                if(!vis[u]){
                    vis[u] = true;
                    dis[u] = dis[v]+1;
                    if(rabbit[u])ans = min(ans, dis[u]);
                    q.push(u);
                }
            }
        }

    }
    cout<<ans<<"\n";
    
    return 0;
}