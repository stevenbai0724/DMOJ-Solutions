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
vector<int>dx {1,-1,0,0};
vector<int>dy {0,0,-1,1};
int n, m;
bool good(int x, vector<vector<int>>psa){

    if(x>n || x>m)return false;
    if(psa[x][x])return false;

    vector<vector<bool>>vis(n+1, vector<bool>(m+1));

    queue<pair<int, int>>q;
    q.push({1,1});
    vis[1][1] = true;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            int checkX = newx+x-1;
            int checkY = newy+x-1;
            if(newx>=1 && newx<=n && newy>=1 && newy<=m && checkX<=n && checkY<=m){
                bool condo = (psa[checkX][checkY] - psa[checkX][newy-1] - psa[newx-1][checkY] + psa[newx-1][newy-1]) ==0;
                if(!vis[newx][newy] && condo ){
                    vis[newx][newy] = true;
                    q.push({newx, newy});
                }
            }
        } 
    }
    return vis[n-x+1][m-x+1];
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    cin>>n>>m;
    vector<vector<int>>psa(n+1, vector<int>(m+1));
    vector<vector<int>>block(n+1, vector<int>(m+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            if(s[j-1]=='X')block[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            psa[i][j] = block[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
  
        }
     
    }
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));

    queue<pair<int, int>>q;
    q.push({1,1});
    vis[1][1] = true;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                if(!vis[newx][newy] && !block[newx][newy]){
                    vis[newx][newy] = true;
                    q.push({newx, newy});
                }
            }
        } 
    }
    if(!vis[n][m]){
        cout<<0<<"\n";
        return 0;
    }
    int l = 1;
    int r = min(n,m)+1;

    while(l+1<r){
        int m = (l+r)/2;
        if(!good(m, psa))r = m;
        else l = m;
    }

    cout<<l<<"\n";

    return 0;
}