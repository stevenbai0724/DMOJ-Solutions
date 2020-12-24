//https://dmoj.ca/problem/graph1p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<vector<int>>adj(n+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(x!=0) adj[i].push_back(j);
        }
    }
    queue<int>q;
    vector<bool>vis(n+1, false);
    vector<int>dis(n+1);
    vis[1] = true;
    q.push(1);


    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int i=0;i<adj[cur].size();i++){
            int next = adj[cur][i];
            if(!vis[next]){
                vis[next] = true;
                dis[next] = dis[cur] +1;
                q.push(next);
            }
        }
    }
    cout<<dis[n];

    return 0;
}