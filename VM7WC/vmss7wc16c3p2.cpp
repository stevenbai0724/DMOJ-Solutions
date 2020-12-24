//https://dmoj.ca/problem/vmss7wc16c3p2
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, start, end;
    cin>>n>>m>>start>>end;

    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1);
    
    for(int i =1;i<=m;i++){
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    queue<int>q;
    q.push(start);
    vis[start] = true;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i =0;i<adj[cur].size();i++){
            int nxt = adj[cur].at(i);
            if(!vis[nxt]){
                vis[nxt] = true;
                q.push(nxt);
            }
        }
    }
    if(vis[end])cout<<"GO SHAHIR!";
    else cout<<"NO SHAHIR!";

    return 0;
}