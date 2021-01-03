//https://dmoj.ca/problem/vmss7wc15c4p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    int ans = 0;
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    vector<int>vis(n);
    vector<int>dis1(n, 1e18);
    vector<int>dis2(n, 1e18);

    q.push({0,0});
    dis1[0] = 0;
    dis2[n-1] = 0;
    while(!q.empty()){
        int y = q.top().second;
        q.pop();
        if(vis[y])continue;
        vis[y] = true;
        for(auto x:adj[y]){
            int neww = x.first;
            int newy = x.second;

            if(neww+dis1[y]<dis1[newy]){
                dis1[newy] = neww+dis1[y];
                q.push({dis1[newy], newy});
            }
        }
    }
    q.push({0,n-1});
    fill(vis.begin(), vis.end(), false);
    while(!q.empty()){
        int y = q.top().second;
        q.pop();
        if(vis[y])continue;
        vis[y] = true;
        for(auto x:adj[y]){
            int neww = x.first;
            int newy = x.second;

            if(neww+dis2[y]<dis2[newy]){
                dis2[newy] = neww+dis2[y];
                q.push({dis2[newy], newy});
            }
        }
    }
    for(int i=0;i<n;i++){
        ans = max(ans, dis1[i]+dis2[i]);
    }
    cout<<ans;
    

    return 0;
}