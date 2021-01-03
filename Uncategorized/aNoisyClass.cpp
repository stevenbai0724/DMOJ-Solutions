//https://dmoj.ca/problem/anoisyclass
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>>adj;
vector<int>colour;
vector<int>p;
bool found = false;
void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            p[u] = v;
            dfs(u);
        }
        if(colour[u]==1){
            p[u] = v;
            found = true;
            return;
        }
    }
    colour[v] = 2;
    if(found || count(colour.begin(), colour.end(),2)==n)return;

}
void cycle(){
    for(int i=1;i<=n;i++){
        if(colour[i]==0) dfs(i);
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(n+1);
    colour.resize(n+1);
    p.resize(n+1);

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    cycle();
    
    if(found)cout<<"N"; 
    else cout<<"Y"; 


    return 0;
}