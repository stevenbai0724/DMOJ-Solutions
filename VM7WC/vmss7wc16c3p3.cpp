//https://dmoj.ca/problem/vmss7wc16c3p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, b, que;
    cin>>n>>m>>b>>que;
    vector<vector<pair<int, int>>>adj(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>q;
    vector<int>dis(n+1, 1e18);

    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    dis[b] = 0;
    q.push({0,b});
    while(!q.empty()){
        int w = q.top().first;
        int y = q.top().second;
        q.pop();
        if(dis[y]<w)continue;
        for(auto nxt: adj[y]){
            int neww = nxt.first;
            int newy = nxt.second;
            if(dis[y]+neww<dis[newy]){
                dis[newy] = dis[y]+neww;
                q.push({dis[newy], newy});
            }
        }
    }
    for(int i=1;i<=que;i++){
        int x; cin>>x;
        if(dis[x]==1e18)cout<<-1<<"\n";
        else cout<<dis[x]<<"\n";
    }
    
    return 0;
}
