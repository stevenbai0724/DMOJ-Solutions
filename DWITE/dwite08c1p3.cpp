//https://dmoj.ca/problem/dwite08c1p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,-1,1};
    vector<vector<char>>arr(11, vector<char>(20));
    vector<vector<vector<int>>>dis(13, vector<vector<int>>(11, vector<int>(20)));
    vector<pair<char, pair<int, int>>>start;
    start.push_back({'/', {0,0}});
    for(int i=1;i<=10;i++){
        string s; cin>>s;
        for(int j=1;j<=19;j++){
            arr[i][j] = s[j-1];
            if(arr[i][j]!='#' && arr[i][j]!='.')start.push_back({arr[i][j], {i,j}});
        }
    }

    
    for(int t=1;t<=12;t++){
        vector<vector<bool>>vis(11, vector<bool>(20));

        int index = (int)start[t].first - 64;

        queue<pair<int, int>>q;
        q.push(start[t].second);

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vis[x][y] = true;
            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx>=1 && newy>=1 && newx<=10 && newy<=19){
                    if(!vis[newx][newy] && arr[newx][newy]!='#'){
                        vis[newx][newy] = true;
                        dis[index][newx][newy] = dis[index][x][y]+1;
                        q.push({newx, newy});
                    }
                }
            }
        }
    }
    
    for(int t=1;t<=5;t++){
        string s; cin>>s;
        int sum = 0;
        if(s.length()==1){
            cout<<0<<"\n";
            continue;
        }
        for(int i=1;i<s.length();i++){
            int index = (int)s[i] - 64;
            int toX, toY;
            for(int j=1;j<=12;j++){

                if(start[j].first==s[i-1]){
                    toX = start[j].second.first;
                    toY = start[j].second.second;
                    break;
                }
            }
            sum+=dis[index][toX][toY];
        }
        cout<<sum<<"\n";
    }
    return 0;
}