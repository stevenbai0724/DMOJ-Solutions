//https://dmoj.ca/problem/graph2p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>>adj;
vector<int>colour;
vector<vector<int>>comp;
int cnt = 0;
void dfs(int v){
    colour[v] = 1;
    comp[cnt].push_back(v);
    for(int u: adj[v]){
        if(colour[u]==0){
            dfs(u);
        }
    }
    colour[v] = 2;
}
void find_comp(){
    for(int i=1;i<=n;i++){
        if(colour[i]==0){
            dfs(i);
            cnt++;
        }
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n;
    adj.resize(n+1);
    colour.resize(n+1);
    comp.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(x)adj[i].push_back(j);
        }
    }
    find_comp();
    for(int i=0;i<n;i++){
        sort(comp[i].begin(), comp[i].end());
    }
    sort(comp.begin(), comp.begin());

    for(auto i: comp){
        if(i.empty())continue;
        for(auto x: i){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}