//https://dmoj.ca/problem/dmopc14ce1p4
#include <bits/stdc++.h>
using namespace std;
#define int double
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
    int c = 4.0/3.0;

    vector<vector<pair<int,int>>>adj(n+1);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>q;
    vector<int>dis(n+1, 1e9);
    vector<int>vis(n+1, false);
    vector<int>p(n+1);
    vector<int>ans;
    for(int i=1;i<=m;i++){
        int x, y, d, s;
        cin>>x>>y>>d>>s;
        adj[x].push_back({d/s*60,y});
        adj[y].push_back({d/s*60,x});
    }
    dis[1] = 0;
    q.push({0,1});

    while(!q.empty()){
        int y = q.top().second;
        int w = q.top().first;
        q.pop();
        if(vis[y])continue;
        vis[y] =true;
        for(auto x: adj[y]){
            int newy = x.second;
            int neww = x.first;
            if(neww+dis[y]<dis[newy]){
                dis[newy] = neww+dis[y];
                q.push({dis[newy], newy});
                p[newy] = y;
            }
        }
    }
    int cur = n;
    ans.push_back(n);
    while(cur!=1){
        cur = p[cur];
        ans.push_back(cur);
    }
    ans.pop_back();
    cout<<ans.size()<<"\n"<<round(dis[n]*c-dis[n]);
    return 0;
}