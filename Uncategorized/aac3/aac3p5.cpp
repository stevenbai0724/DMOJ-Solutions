//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<bool>>puddle(n+1, vector<bool>(m+1));
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,1,-1};

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            puddle[i][j] = false;
            if(s[j-1]=='.')puddle[i][j] = true;
        }
    }
    
    for(int i=1;i<=m;i++){

        if(puddle[n][i]){
            cout<<-1;
            if(i<m)cout<<" ";
            continue;
        }

        int mx = 0;

        for(int j=0;j<=n;j++){

            queue<pair<int, int>>q;
            vector<vector<bool>>vis(n+1, vector<bool>(m+1));
            q.push({n,i});
            vis[n][i] = true;

            while(!q.empty()){
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    
                    int newx = curx+dx[k];
                    int newy = cury+dy[k];
                    if(newx<1 || newx>n ||newy<1 || newy>m)continue;
                    if(vis[newx][newy])continue;

                    if(!puddle[newx][newy]){
                        q.push({newx, newy});
                        vis[newx][newy] = true;
                    }
                    
                    if(puddle[newx][newy]){
                        int len = 1;

                        while(newx+dx[k]>=1 && newx+dx[k]<=n && newy+dy[k]>=1 && newy+dy[k]<=m){
                            newx+=dx[k];
                            newy+=dy[k];
                            cout<<newx<<" "<<newy<<" "<<n<<" "<<m<<" "<<dx[k]<<" "<<dy[k]<<"\n";
                        }
                        cout<<"ree\n";

                        if(len>j)continue;
                        if(!puddle[newx][newy]){
                            vis[newx][newy] = true;
                            q.push({newx, newy});
                        }

                    }
                }
            }

            for(int k=1;k<=m;k++){
                if(vis[1][k])mx = j;
            }
        }

        if(mx==n){
            cout<<0;
        }
        else cout<<mx;

        if(i<m)cout<<" ";
   


    }
    std::cout<<"\n";
    



    return 0;
}