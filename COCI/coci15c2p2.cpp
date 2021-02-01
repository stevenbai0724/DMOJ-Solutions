//https://dmoj.ca/problem/coci15c2p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>>adj;
int ans = 1;
bool check(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(i==j)continue;
            auto it = find(adj[arr[i]].begin(), adj[arr[i]].end(), arr[j]);
            if(it!=adj[arr[i]].end())return false;
        }
    }
    return true;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(n+1);
    ans+=n;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<(1<<n);i++){
        vector<int>arr;
        for(int j=0;j<n;j++){
            if((1<<j)&i)arr.push_back(j+1);
        }
        if(arr.size()>1){
            if(check(arr)){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";

 
}