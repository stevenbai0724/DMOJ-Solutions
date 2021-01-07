//https://dmoj.ca/problem/tree1
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj(5);
vector<int>colour(5);

void dfs(int v){
    colour[v] = 1;
    for(auto u: adj[v]){
        if(colour[u]==0){
            dfs(u);
        }
    }
    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int count = 0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            int n; cin>>n;
            if(n==1){
                adj[i].push_back(j);
                count++;
            }
        }
    }
    if(count!=6){
        cout<<"No";
        return 0;
    }
    dfs(1);
    for(int i=1;i<=4;i++){
        if(colour[i]!=2){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";


    return 0;
}