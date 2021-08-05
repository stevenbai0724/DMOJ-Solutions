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
int n ,q;

vector<int>colour;
vector<int>dis;
vector<int>parent;
vector<vector<int>>adj;

void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            parent[u] = v;
            dis[u] = dis[v] + 1;
            dfs(u);
        }
    }
    colour[v] = 2;
}
int bfs(int from, int to){
    queue<int>q;
    q.push(from);
    vector<int>vis(n+1);
    vector<int>dist(n+1);
    vis[from] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int u: adj[cur]){
            if(!vis[u]){
                vis[u] = true;
                dist[u] = 1 + dist[cur];
                q.push(u);
            }
        }
    }
    return dist[to];
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>q;
    dis.resize(n+1);
    colour.resize(n+1);
    parent.resize(n+1);
    adj.resize(n+1);

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    while(q--){
        int x; cin>>x;
        vector<int>des(x+1);
        for(int i=1;i<=x;i++){
            cin>>des[i];
        }
        int ans = 1e9;

        //try nodes for v
        //get path from 1 to v
        //get min dis from des to 

        for(int i=2;i<=n;i++){
            vector<int>path;
            int cnt = 0;
            int cur = i;
            while(cur!=1){
                path.push_back(cur);
                cur = parent[cur];
            }
            path.push_back(1);

            for(int j=1;j<=x;j++){
                int cur = des[j];
                int mn = 1e9;

                for(auto k: path){
                    mn = min(mn, bfs(k, cur));
                }
                if(mn <0)mn = 0;
                cnt+=mn;

            }
            ans = min(ans, cnt);

        }
        cout<<ans<<"\n";

        
    }



    return 0;
}