//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    int ans = 1e18;

    vector<pair<int, pair<int,int>>>edges(n+1);

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        if(w&1)w = 1;
        else w = 2;

        edges[i] = {x, {w,y}};
        
    }

    for(int t = 0; t<n;t++){
        vector<vector<pair<int, int>>>adj(n+1);
      
        vector<vector<int>>dis(n+1, vector<int>(n+1));

        for(int i=1;i<n;i++){
            
            int x = edges[i].first;
            int w = edges[i].second.first;
            int y = edges[i].second.second;

            if(i==t)w++;

            adj[x].push_back({w,y});
            adj[y].push_back({w,x});
        }

        for(int i=1;i<=n;i++){

            vector<int>vis(n+1);
            queue<pair<int, int>>q;

            q.push({0,i});
            vis[i] = true;
            while(!q.empty()){
                int w = q.front().first;
                int cur = q.front().second;
                q.pop();

                for(auto pp: adj[cur]){
                    int neww = pp.first;
                    int to = pp.second;

                    if(!vis[to]){
                        vis[to] = true;
                        dis[i][to] = dis[i][cur] + neww;
                        q.push({dis[i][to], to});
                    }
                }
            }
        }
        int odd = 0, even = 0;
        vector<vector<bool>>check(n+1, vector<bool>(n+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(check[i][j] || check[j][i])continue;
                check[i][j] = true;

                if(dis[i][j]%2==0){
                    even++;
                }
                else odd++;
            }
        }

        ans = min(ans, abs(even-odd));




    

    }
    cout<<ans<<"\n";


    return 0;
}