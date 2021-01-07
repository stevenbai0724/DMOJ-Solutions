//https://dmoj.ca/problem/graph2p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>>adj;
vector<int>colour;
bool found = false;

void dfs(int v){
    colour[v] = 1;
    for(auto u : adj[v]){
        if(found)return;
        if(colour[u]==0){
            dfs(u);
        }
        if(colour[u]==1){
            found = true;
            return;
        }
    }
    colour[v] = 2;


}
bool cycle(){
    for(int i=1;i<=n;i++){
        if(colour[i]==0)dfs(i);
        if(found)return true;
    }
    return false;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    adj.resize(n+1);
    colour.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(x)adj[i].push_back(j);
        }
    }
    if(cycle())cout<<"NO";
    else cout<<"YES";


    return 0;
}