//https://dmoj.ca/problem/vmss15c1p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    int count = 0;
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));
    vector<int>X{1,-1,0,0};
    vector<int>Y{0,0,-1,1};
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j] && arr[i][j]!='X'){
                count++;
                queue<pair<int,int>>q;
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    vis[x][y] = true;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int newx = x+X[k];
                        int newy = y+Y[k];
                        if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                            if(arr[newx][newy]!='X' && !vis[newx][newy]){
                                vis[newx][newy] = true;
                                q.push({newx, newy});
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<count;
    return 0;
}