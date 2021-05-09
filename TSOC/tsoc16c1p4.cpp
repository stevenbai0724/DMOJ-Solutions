//https://dmoj.ca/problem/tsoc16c1p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<int>dy{1,-1,0,0};
    vector<int>dx{0,0,-1,1};
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));
    int ans = 0;
    queue<pair<int, int>>q;
    
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j] && arr[i][j]!='#'){
                bool found = false;
                queue<pair<int, int>>q;
                q.push({i,j});
                vis[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    found |= arr[x][y]=='M';
                    q.pop();
                    for(int k=0;k<4;k++){
                        int newx = x+dx[k];
                        int newy = y+dy[k];
                        if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                            if(arr[newx][newy]!='#' && !vis[newx][newy]){
                                vis[newx][newy] = true;
                                found |= arr[newx][newy]=='M';
                                q.push({newx, newy});
                            }
                        }
                    }
                }
                ans+=found;
            }
        }
    }
    cout<<ans<<"\n";


    return 0;
}