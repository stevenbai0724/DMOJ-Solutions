//https://dmoj.ca/problem/bts16p5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
int n,c,k;
vector<int>cherry;
vector<vector<pair<int, int>>>adj;
vector<pair<pair<int, int>, int>>edges;
int curWeight = 0;
int curCherry = 0;
int ans = 0;

void dfs(int v){

    curCherry += cherry[v];
    for(auto p: adj[v]){
        int w = p.first;
        int u = p.second;

        curWeight+=w;

        dfs(u);

    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>c>>k;
    cherry.resize(n+1);
    adj.resize(n+1);
    edges.resize(n);

    for(int i=1;i<=n;i++){
        cin>>cherry[i];
    }
    for(int i=1;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        if(x>y) swap(x, y);
        adj[x].push_back({w,y});
        edges[i] = {{x,y}, w};
    }
    for(int i=1;i<n;i++){
        int from = edges[i].first.first;
        int to = edges[i].first.second;
        int weight = edges[i].second;

        curWeight = weight;
        dfs(to);

        ans += (curWeight<=k && curCherry>=c);

        curWeight = 0;
        curCherry = 0;
    }
    cout<<ans<<"\n";


    return 0;
}