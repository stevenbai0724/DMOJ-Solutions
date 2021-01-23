//https://dmoj.ca/problem/coci20c2p2
#include <bits/stdc++.h>
using namespace std;

int n; 
double r = 0;
double ans = 1e18;
vector<bool>vis;
vector<pair<int, int>>loc;
vector<double>len;

bool dis(pair<int, int>a, pair<int, int>b){
    double dx = abs(a.first-b.first);
    double dy = abs(a.second-b.second);
    double radius =  sqrt((dx*dx)+(dy*dy))/2.0;
    return r>=radius;
}
bool bfs(){
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        vis[cur] = true;

        for(int i=1;i<=n;i++){
            if(!vis[i] && dis(loc[cur], loc[i])){
                vis[i] = true;
                q.push(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])return false;
    }
    return true;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    loc.resize(n+1);
    vis.resize(n+1);
    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        loc[i] = {x,y};
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1; i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            double dx = abs(loc[i].first-loc[j].first);
            double dy = abs(loc[i].second-loc[j].second);
            double rad =  sqrt((dx*dx)+(dy*dy))/2.0;
            len.push_back(rad);
        }
        
    }
    sort(len.begin(), len.end());
    int lo = 0;
    int hi = len.size()-1;
    while(lo+1<hi){
        int m = (lo+hi)/2;
        r = len[m];
        if(bfs())hi = m;
        else lo = m; 

        for(int i=1;i<=n;i++){
            vis[i] = false;
        }
    }
    cout<<setprecision(25)<<fixed<<len[hi]<<"\n";    

    return 0;
}