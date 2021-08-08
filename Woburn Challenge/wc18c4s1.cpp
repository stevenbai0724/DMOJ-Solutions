//https://dmoj.ca/problem/wc18c4s1
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin>>n>>m>>k;
    vector<char>race(m+1);
    vector<vector<int>>adj(n+1);
    string s; cin>>s;
    for(int i=0;i<n;i++){
        race[i+1] = s[i];
    }

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>colour(n+1,0);
    int curCol = 1;
    for(int i=1;i<=n;i++){  
        if(colour[i]==0){
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                char curRace = race[cur];
                q.pop();
                colour[cur] = curCol;

                for(int x: adj[cur]){
                    if(race[x]==curRace && colour[x]==0){
                        colour[x] = curCol;
                        q.push(x);
                    }
                }

            }
            curCol++;
        }
    }
    int ans = 0;
    while(k--){
        int x, y;
        cin>>x>>y;
        if(colour[x]==colour[y])ans++;
    }
    cout<<ans<<"\n";

    return 0;
}