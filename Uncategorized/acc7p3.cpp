#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int>points;
struct DSU{

    int size;
    vector<int>parent, sz;
    void init(int n){
        size = n;
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        return find(parent[x]);
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return ;
        if(sz[x]<sz[y]){
            sz[y] += sz[x];
            size--;
            parent[x] = y;
        }
        else{
            sz[x] += sz[y];
            size--;
            parent[y] = x;
        }

    }
};
struct edge{
    int x, y, w;

};
bool comp(edge a, edge b){
    return a.w<b.w;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    DSU ds;
    ds.init(n);

    points.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>points[i];
    }

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        ds.Union(x, y);

    }

    int ans = 0;

    vector<edge>arr;
    for(int i=1;i<n;i++){
        edge e = {i,i+1,points[i+1]-points[i]};
        arr.push_back(e);
    }
    sort(arr.begin(), arr.end(), comp);

    for(edge e: arr){
        if(ds.find(e.x) != ds.find(e.y)){
            ds.Union(e.x, e.y);
            ans += e.w;
        }
    }

    cout<<ans<<"\n";


    return 0;
}