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

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<vector<int>>adj(n+1);
    vector<vector<bool>>vis(n+1, vector<bool>(n+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='1'){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        queue<int>q;
        q.push(i);
        vis[i][i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int to: adj[cur]){
                if(!vis[i][to]){
                    vis[i][to] = true;
                    q.push(to);
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j] && !vis[j][i])ans++;
        }
    }
    cout<<ans/2<<"\n";
    
    return 0;
}