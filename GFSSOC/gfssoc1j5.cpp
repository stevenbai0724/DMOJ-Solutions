//https://dmoj.ca/problem/gfssoc1j5
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n,m,d;

    cin>>n>>m>>d;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>ans(n+1, vector<int>(n+1));

    for(int i =0;i<m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);

    }
    for(int i = 1; i<=n; i++){
        queue<int>q;
        q.push(i);
        vector<bool>vis(n+1);
        vector<int>dis(n+1);
      

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int j =0; j<adj[cur].size(); j++){
                int nxt = adj[cur].at(j);
                if(!vis[nxt]){
                    vis[nxt] = true;
                    dis[nxt] = dis[cur]+d;
                    q.push(nxt);
                    ans[i][nxt] = dis[nxt];
                }
            }
        }
    }
    int x; cin>>x;
    for(int i =0 ; i<x; i++){
        int a, b;
        cin>>a>>b;
        if(ans[a][b]==0) cout<<"Not enough hallways!"<<"\n";
        else cout<<ans[a][b]<<"\n";
    }
    return 0;
}