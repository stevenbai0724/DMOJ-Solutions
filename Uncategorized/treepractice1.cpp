//https://dmoj.ca/problem/treepractice1
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<pair<int, int>>>adj;
vector<int>dis;
vector<int>colour;
vector<int>p;
int nd;
int start;
int mx = 0;
int ra = 1e18;
int dia = 0;

void clear(){
    fill(dis.begin(), dis.end(), 0);
    fill(colour.begin(), colour.end(),0);
    fill(p.begin(), p.end(), 0);
    mx = 0;
}
void dfs(int v){
    colour[v] = 1;
    for(auto u : adj[v]){
        int newu = u.second;
        int neww = u.first;
        if(colour[newu]==0){
            p[newu] = v;
            dis[newu] = dis[v]+neww;
            if(dis[newu]>mx){
                mx = dis[newu];
                nd = newu;
            }
            dfs(newu);
        }
    }
    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    adj.resize(n+1);
    colour.resize(n+1);
    dis.resize(n+1);
    p.resize(n+1);

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    dfs(1);
    clear();
    start = nd;

    dfs(nd);
    dia = mx;
    cout<<dia<<"\n";

    
    int cur = p[nd];
    while(cur!=start){
        
        ra = min(ra, max(dis[cur], dia- dis[cur]));
        cur = p[cur];
    }
    cout<<ra<<"\n";



    return 0;
}