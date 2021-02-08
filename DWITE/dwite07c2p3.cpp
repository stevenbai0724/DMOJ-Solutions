//https://dmoj.ca/problem/dwite07c2p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    gp_hash_table<int, pair<int, int>>mp;

    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,-1,1};
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
            if((int)arr[i][j] >=49 && (int)arr[i][j]<=53){
                mp[(int)arr[i][j]-48] = {i,j};
            }
        }
    }

    for(int i=1;i<=5;i++){
        queue<pair<int, int>>q;
        q.push(mp[i]);
        int cnt = 0;
        vector<vector<bool>>vis(n+1, vector<bool>(m+1));
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            vis[x][y] = true;
            q.pop();
            for(int k = 0; k<4;k++){
                int newx = x+dx[k];
                int newy = y+dy[k];
                if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                    if(arr[newx][newy]!='#' && !vis[newx][newy]){
                        cnt++;
                        vis[newx][newy] = true;
                        q.push({newx, newy});
                    }
                }
            }
            
        }
        cout<<cnt+1<<"\n";
    }


    return 0;
}