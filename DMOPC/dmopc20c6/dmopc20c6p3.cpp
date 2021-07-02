//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

int n, m;
vector<int>p(5e5+2);
vector<int>colour(5e5+2);
vector<bool>cycle(5e5+2, true);

vector<set<int>>adj(5e5+2);
bool found = false;
void reset(){
    for(int i=1;i<=n;i++){
        p[i] = 0;
        colour[i] = 0;
    }
}
void trace(int nd, int start){
    cycle[nd] = false;
    while(true){
        nd = p[nd];
        cycle[nd] = false;
        if(nd == start)break;

    }
}
void dfs(int v){
    colour[v] = 1; 
    for(int u: adj[v]){
        if(colour[u]==0){
            p[u] = v;
            dfs(u);
        }
        if(colour[u]==1){
            trace(v, u);
        }
    }
    colour[v] = 2;
    
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
    }
    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        if(a==b){
            cycle[a] = false;
            continue;
        }
        adj[a].insert(b);
        
    }

    for(int i=1;i<=n;i++){
        if(colour[i] == 0)dfs(i);
    }

    for(int i=1;i<=n;i++){
        cout<<cycle[i];
        if(i<n)cout<<" ";
    }
    cout<<"\n";
    


    

    return 0;
}