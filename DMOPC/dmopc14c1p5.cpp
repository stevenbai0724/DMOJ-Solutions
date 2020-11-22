https://dmoj.ca/problem/dmopc14c1p5
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int start = a*2000 +b;
    int end = c*2000 +d;
    int close = (int)(1e9);

    for(int i =0; i<n;i++){
        string s; cin>>s;
        for(int j=0;j<m;j++){
            arr[i][j] = s[j];

        }
    }
    int p; cin>>p;
    for(int i=0;i<p; i++){
        int x,y;
        cin>>x>>y;
        arr[x][y] = 'P';
    }

    queue<int>q;
    q.push(start);
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));
    vector<vector<int>>dis(n+1, vector<int>(m+1));
    vis[start/2000][start%2000] = true;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        int x = cur/2000;
        int y = cur%2000;
        vector<int>changeX {1,-1,0,0};
        vector<int>changeY {0,0,-1,1};

        for(int i =0; i<4;i++){
            int newx = x + changeX[i];
            int newy = y + changeY[i];

            if(newx>=0 && newx<n && newy>=0 && newy<m){
                if(arr[newx][newy]!='X' && !vis[newx][newy]){
                    vis[newx][newy] = true;
                    dis[newx][newy] = dis[x][y]+1;
                    q.push(newx*2000 + newy);
                    if(arr[newx][newy]=='P'){
                        close = min(close, dis[newx][newy]);
                    }
                }   
            }
        }
    }
   
    if(close!=(int)(1e9))cout<<dis[end/2000][end%2000]-close;
    else cout<<dis[end/2000][end%2000];
    return 0;
}
