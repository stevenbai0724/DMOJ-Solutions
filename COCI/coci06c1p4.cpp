//https://dmoj.ca/problem/coci06c1p4
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    int start = 0;
    int end = 0;
    int floodCount =0; //number of floods from the start
    vector<int>f; //locations of all the intial floods
    vector<vector<int>>dis(n+1, vector<int>(m+1));
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));
    string s = "KAKTUS";
    vector<int>changeX {1,-1,0,0};
    vector<int>changeY {0,0,1,-1};

    for(int i = 1; i<=n; i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
            if(arr[i][j]=='S') start = i*100 + j;
            if(arr[i][j]=='D') end  = i*100 +j;
            if(arr[i][j]=='*'){
                floodCount++;
                f.push_back(i*100 +j);
            }
        }   
    }
    //stores min time for flood to get to each spot on the map
    vector<vector<int>>floodMap(n+1,vector<int>(m+1)); 
    for(int i =1; i<=n; i++){
        for(int j=1;j<=m; j++){
            floodMap[i][j] = (int)(1e9);
        }
    }
    
    for(int i =0;i<floodCount; i++){
        vector<vector<int>>dis2(n+1, vector<int>(m+1));
        vector<vector<bool>>vis2(n+1, vector<bool>(m+1));
        queue<int>q;
        q.push(f.at(i));
        vis2[f.at(i)/100][f.at(i)%100] =true;
        floodMap[f.at(i)/100][f.at(i)%100] = 0;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            int x = cur/100;
            int y = cur%100;

            for(int i =0; i<4; i++){
                int newx = x + changeX[i];
                int newy = y + changeY[i];
                if(newx>0 && newx<=n && newy>0 && newy<=m){
                    if(arr[newx][newy]!='X' && arr[newx][newy]!='D' && !vis2[newx][newy]){
                        vis2[newx][newy] = true;
                        dis2[newx][newy] = dis2[x][y]+1;
                        floodMap[newx][newy] = min(floodMap[newx][newy], dis2[newx][newy]);
                        q.push(newx*100 + newy);
                    }
                }
            }
        }
    }
    queue<int>q;
    q.push(start);
    vis[start/100][start%100] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        int x = cur/100;
        int y = cur%100;

        
        for(int i=0;i<4;i++){
            int newx = x + changeX[i];
            int newy = y + changeY[i];
            
            if(newx>0 && newx<=n && newy>0 && newy<=m){
                if(arr[newx][newy]!='X' && !vis[newx][newy] ){
                    if(dis[x][y]+1<floodMap[newx][newy]){
                        dis[newx][newy] = dis[x][y]+1;
                        q.push(newx*100+newy);
                        vis[newx][newy]= true;
                    }                    
                }

            }
        }

    }
    
    if(!vis[end/100][end%100]) cout<<s;
    else cout<<dis[end/100][end%100];

    return 0;
}