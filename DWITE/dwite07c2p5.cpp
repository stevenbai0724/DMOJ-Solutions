//https://dmoj.ca/problem/dwite07c2p5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 5;
    while(t--){
        int n, m;
        cin>>n>>m;
        int ans = 0;
        vector<pair<int, int>>edges(m+1);
        for(int i=1;i<=m;i++){
            int a, b;
            cin>>a>>b;
            edges[i] = {a,b};
        }
        for(int i=1;i<=m;i++){
            vector<vector<int>>adj(n+1);
            vector<bool>vis(n+1);
            for(int j=1;j<=m;j++){
                if(j==i)continue;
                int a = edges[j].first;
                int b = edges[j].second;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            queue<int>q;
            q.push(1);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int to: adj[cur]){
                    if(!vis[to]){
                        vis[to] = true;
                        q.push(to);
                    }
                }
            }
            if(count(vis.begin(), vis.end(), 1)!=n)ans++;

        }
        cout<<ans<<"\n";
    }


    return 0;
}