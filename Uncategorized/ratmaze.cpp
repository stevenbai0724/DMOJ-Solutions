//https://dmoj.ca/problem/ratmaze
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,-1,1};
    int n; cin>>n;
    vector<vector<int>>arr(n+1, vector<int>(n+1));
    vector<vector<bool>>vis(n+1, vector<bool>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    queue<pair<int, int>>q;
    q.push({1,1});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        vis[x][y] = true;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=1 && newy>=1 && newx<=n && newy<=n){
                if(!vis[newx][newy] && arr[newx][newy]!=1){
                    vis[newx][newy] = true;
                    q.push({newx, newy});
                }
            }
        }
    }
    if(!vis[n][n])cout<<"no\n";
    else cout<<"yes\n";
    
    return 0;

}