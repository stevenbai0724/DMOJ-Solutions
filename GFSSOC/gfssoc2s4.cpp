//https://dmoj.ca/problem/gfssoc2s4
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct edge{
    int x, y, w;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<vector<pair<int,int>>>adj2(n+1);
    

    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({w,y});
        adj2[y].push_back({w,x});
    }

    int d; cin>>d;

    vector<edge>pile;

    for(int i=1;i<=d;i++){
        int x, y, w;
        cin>>x>>y>>w;
        pile.push_back({x,y,w});
    }   

    vector<int>dis1(n+1, 1e18); dis1[1] = 0;
    vector<int>dis2(n+1, 1e18); dis2[n] = 0;

    q.push({0,1});

    while(!q.empty()){
        int w = q.top().first;
        int y = q.top().second;
        q.pop();

        if(dis1[y]<w)continue;

        for(auto nxt: adj[y]){
            int neww = nxt.first;
            int newy = nxt.second;

            if(neww + dis1[y]<dis1[newy]){
                dis1[newy] = dis1[y] + neww;
                q.push({dis1[newy], newy});
            }

        }

    }
    q.push({0,n});

    while(!q.empty()){
        int w = q.top().first;
        int y = q.top().second;
        q.pop();

        if(dis2[y]<w)continue;

        for(auto nxt: adj2[y]){
            int neww = nxt.first;
            int newy = nxt.second;

            if(neww + dis2[y]<dis2[newy]){
                dis2[newy] = dis2[y] + neww;
                q.push({dis2[newy], newy});
            }
        }
    }
    int best = dis1[n];

    for(auto e : pile){
        best = min (best, dis1[e.x] + e.w + dis2[e.y]);
    }

    if(best==1e18)cout<<-1<<"\n";
    else cout<<best<<"\n";
    return 0;
}