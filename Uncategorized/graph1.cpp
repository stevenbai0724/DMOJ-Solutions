//https://dmoj.ca/problem/graph1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1);

    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int start, end;
    cin>>start>>end;
    queue<int>q;
    vis[start] = true;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto to: adj[cur]){
            if(!vis[to]){
                vis[to] = true;
                q.push(to);
            }
        }
    }
    cout<<vis[end]<<"\n";
    
    


    return 0;
}