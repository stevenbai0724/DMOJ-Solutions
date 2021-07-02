//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
int n, q, u, k;
vector<int>p(2e3+5);
vector<int>colour(2e3+5);
vector<int>arr(2e3+5);
vector<int>freq(2e3+5);
vector<vector<int>>adj(2e3+5);
vector<int>in(2e3+5);
int distinct = 0;
set<int>cnt;
bool found = false;
int ans = 0;

void reset(){
    for(int i=1;i<=n;i++){
        colour[i] = 0;
        in[i] = 0;
    }
    ans = 0;
}
void dfs(int v){

    colour[v] = 1;

    for(int u: adj[v]){
        if(colour[u]==0){

            in[u] ++ ;
            dfs(u);
            p[u] = v;

        }
    }

    colour[v] = 2;  
}
void topo(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0)q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        
        q.pop();
        int clr = arr[cur];
        freq[clr]--;
        if(freq[clr]!=0){
            ans++;
            for(int to: adj[cur]){
                in[to]--;
                if(in[cur]==0)q.push(to);
            }
        }
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
        cnt.insert(arr[i]);
        distinct = cnt.size();

    }
    for(int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(q--){
        cin>>u>>k;
        if(k>distinct){
            cout<<0<<"\n";
            continue;
        }
        dfs(u);
        topo();
        cout<<ans<<"\n";
        reset();

    }
    

    return 0;
}