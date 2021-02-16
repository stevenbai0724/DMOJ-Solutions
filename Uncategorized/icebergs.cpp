//https://dmoj.ca/problem/icebergs
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, a, b;
    cin>>n>>m>>a>>b;
    vector<vector<char>>arr(n +1, vector<char>(m+1));
    vector<vector<int>>psa(n+1, vector<int>(m+1));

    for(int i =1; i<=n; i++){
        string s;cin>>s;
        for(int j = 1; j<=m; j++){
            if(s[j-1] =='#'){
                arr[i][j] = 1;
            }
        }
    }
    for(int i =1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            psa[i][j] = psa[i][j-1] - psa[i-1][j-1] + psa[i-1][j]+arr[i][j];
        }
    }
    if(psa[a][b]==0){
        queue<int>q;
        q.push(10001);
        vector<int>changeX {1,-1,0,0};
        vector<int>changeY {0,0,-1,1};
        vector<vector<bool>>vis(n+1, vector<bool>(m+1));
        vector<vector<int>>dis(n+1, vector<int>(m+1));
        vis[1][1] = true;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            int x = cur/10000;
            int y = cur%10000;
        

            for(int i = 0; i<4; i++){
                int newx = x + changeX[i];
                int newy = y + changeY[i]; 
                int c = newx+a-1;
                int d = newy+b-1;
                if(newx>0 && newx<=n && newy>0 && newy<=m && c>0 && c<=n && d>0 && d<=m){
                    if((psa[c][d]-psa[newx-1][d]+psa[newx-1][newy-1]-psa[c][newy-1]) ==0 && !vis[newx][newy]){
                        vis[newx][newy]= true;
                        dis[newx][newy] = dis[x][y]+1;
                        q.push(newx*10000 + newy);
                    }
                }
            }
            
        }
        if(!vis[n-a+1][m-b+1]) cout<<-1;
        else cout<< dis[n-a+1][m-b+1];
    }
    else cout<<-1;



    return 0;
}
