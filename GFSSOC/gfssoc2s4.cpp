//https://dmoj.ca/problem/gfssoc2s4
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<vector<pair<int,int>>>adj2(n+1);
    vector<bool>vis1(n+1);
    vector<bool>vis2(n+1);
    vector<int>dis1(n+1, 1e18);
    vector<int>dis2(n+1, 1e18);
    dis1[1] = 0;
    dis2[n] = 0;

    while(m--){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj2[y].push_back({w,x});
    }
    q.push({0,1});
    while(!q.empty()){
        int y = q.top().second;
        q.pop();
        if(vis1[y])continue;
        vis1[y] = true;
        for(auto x : adj[y]){
            int neww = x.first;
            int newy = x.second;
            if(neww+dis1[y]<dis1[newy]){
                dis1[newy] = neww+dis1[y];
                q.push({dis1[newy], newy});
            }
        }
    }
    q.push({0,n});
    while(!q.empty()){
        int y = q.top().second;
        q.pop();
        if(vis2[y])continue;
        vis2[y] = true;
        for(auto x : adj2[y]){
            int neww = x.first;
            int newy = x.second;
            if(neww+dis2[y]<dis2[newy]){
                dis2[newy] = neww+dis2[y];
                q.push({dis2[newy], newy});
            }
        }
    }
    int ans = dis1[n];
    int d; cin>>d;
    while(d--){
        int x,y,w;
        cin>>x>>y>>w;
        ans = min(ans, dis1[x]+dis2[y]+w);
    }
    
    if(ans!=1e18)cout<<ans;
    else cout<<-1;
    return 0;
}