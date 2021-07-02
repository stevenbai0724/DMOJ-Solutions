//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
struct DSU{

    vector<int>parent, sz;

    void init(int n){
        parent.resize(n+1);
        sz.resize(n+1);

        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;

        }

    }
    int find(int x){
        if(parent[x]==x)return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return ;
        if(sz[x]<sz[y]){
            sz[y] += sz[x];
            parent[x] = y;

        }
        else{
            sz[x] += sz[y];
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
    
    int n, k;
    cin>>n>>k;

    DSU ds;
    ds.init(n);

    vector<edge>arr;

    for(int i=1;i<n;i++){
        int w; cin>>w;
        edge e {i, i+1, w};
        arr.push_back(e);
    }
    for(int i=1;i<=n;i++){
        if(i+k > n)break;
        edge e = {i, i+k, 0};
        arr.push_back(e);
    }
    sort(arr.begin(), arr.end(), comp);
    int ans = 0;
    for(edge e: arr){
        if(ds.find(e.x) != ds.find(e.y)){
            ans += e.w;

            ds.Union(e.x, e.y);

        }
    }

    cout<<ans<<"\n";



    

    return 0;
}