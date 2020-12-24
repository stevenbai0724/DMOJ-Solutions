//https://dmoj.ca/problem/graph3p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>>>adj(n+1);
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    vector<int>dis(n+1, 1e18);
    dis[1] =0;
    q.push({0,1});
    while(!q.empty()){
        pair<int, int>cur = q.top(); q.pop();
        int w = cur.first;
        int y = cur.second;

        if(dis[y]<w) continue; //skip if processed
        for(auto nxt : adj[y]){ //iterate through all pairs adj to cur
            int neww = nxt.first;
            int newy = nxt.second;
            if(neww+dis[y]<dis[newy]){//check if distance can be optimized
                dis[newy] = neww+dis[y];
                q.push({dis[newy], newy});
            }
        }
    }
    cout<<dis[n];



    return 0;
}