//https://dmoj.ca/problem/vmss15c1p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t, n, m, g;
    cin>>t>>n>>m>>g;
    n++;
    vector<int>arr(g+1);
    vector<vector<pair<int, int>>>adj(n+1);
    vector<int>dis(n+1, 1e18);
    vector<int>vis(n+1); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    for(int i=1;i<=g;i++){
        cin>>arr[i];
        arr[i]++;
    }
    while(m--){
        int x, y, w;
        cin>>x>>y>>w;
        x++; y++;
        adj[x].push_back({w,y});
    }
    dis[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        if(vis[v])continue;
        vis[v] = true;

        for(auto p: adj[v]){
            int w = p.first;
            int u = p.second;
            if(dis[v]+w < dis[u]){
                dis[u] = dis[v]+w;
                q.push({dis[u], u});
            }
        }
    }
    
    int ans = 0;
    for(int i=1;i<=g;i++){
        ans+=(dis[arr[i]]<=t);
    }
    cout<<ans<<"\n";



    return 0;
}