//https://dmoj.ca/problem/dmpg17s2

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);

    while(m--){
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        if(a>b){
            adj[x].push_back(y);
        }
        else adj[y].push_back(x);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        queue<int>q;
        q.push(i);
        vector<int>vis(n+1);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(nxt==i){
                    ans++;
                    goto nxt;
                }
                if(!vis[nxt]){
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        nxt:;

    }
    cout<<ans<<"\n";


    return 0;
}