//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;
#define int long long

const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, k;
    cin>>n>>k;
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,1,-1};

    vector<vector<bool>>block(n+1, vector<bool>(n+1));

    while(k--){
        int x, y;
        cin>>x>>y;

        x = n-x+1;

        block[x][y] = true;

    }
    vector<vector<bool>>vis(n+1, vector<bool>(n+1));
    vector<vector<int>>dis(n+1, vector<int>(n+1));
    queue<pair<int, int>>q;
    
    vis[1][n] = true;
    q.push({1,n});
    
    while(!q.empty()){
        
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];

            if(newx>=1 && newx<=n && newy>=1 && newy<=n){
                if(!vis[newx][newy] && !block[newx][newy]){
                    vis[newx][newy] = true;
                    dis[newx][newy] = dis[curx][cury]+1;
                    q.push({newx, newy});
                }
            }
        }
    }
    if(!vis[n][1]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    int r = n;
    int c = 1;
    string ans = "";

    while(r!= 1 || c!=n){
        
        char ch = 'a';
        int newr, newc;

        for(int i=0;i<4;i++){ 
            char temp;
            switch(i){
                case 0: 
                temp = 'D';
                break;

                case 1:
                temp = 'U';
                break;

                case 2:
                temp = 'R';
                break;

                case 3:
                temp = 'L';
                break;
            }
            int newx = r + dx[i];
            int newy = c + dy[i];

            if(newx>=1 && newx<=n && newy>=1 && newy<=n){
                if(vis[newx][newy] && dis[newx][newy]<dis[r][c]){
                    if((int)temp<(int)ch){
                        ch = temp;
                        newr = newx;
                        newc = newy;
                    }
                }
            }
        }
        ans+=ch;
        r = newr;
        c = newc;

    }  
    cout<<ans<<"\n";

    return 0;
}