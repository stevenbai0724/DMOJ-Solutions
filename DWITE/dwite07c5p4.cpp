//https://dmoj.ca/problem/dwite07c5p4
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>dx{1,1,1,0,-1,-1,-1,0};
    vector<int>dy{1,0,-1,-1,-1,0,1,1};
    int t = 5;
    while(t--){

        vector<vector<char>>arr(6, vector<char>(11)); 
        vector<vector<bool>>vis(6, vector<bool>(11));
        vector<vector<int>>dis(6, vector<int>(11));
        for(int i=0;i<=5;i++){
            fill(arr[i].begin(), arr[i].end(), ' ');
        }
        pair<int, int> start ,end;

        for(int i=1;i<=6;i++){
            string s; 
            getline(cin, s);
            if(s=="xxxxxxxxxx")break;
            for(int j=1;j<=10;j++){
                arr[i][j] = s[j-1];
                if(arr[i][j]=='S')start = {i,j};
                if(arr[i][j]=='E')end = {i,j};
            }
        }
        queue<pair<int, int>>q;
        q.push(start);
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            vis[x][y] = true;
            q.pop();
            for(int i=0;i<8;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                

                if(newx>=1 && newy>=1 && newx<=5 && newy<=10){
                    if(arr[newx][newy]!=' ' && arr[newx][newy]!='x' && !vis[newx][newy]){
                        q.push({newx,newy});
                        dis[newx][newy] = dis[x][y] +1;
                        vis[newx][newy] = true;
                    }
                }
            }
        }
        cout<<dis[end.first][end.second]<<"\n";

    }

    return 0;
}