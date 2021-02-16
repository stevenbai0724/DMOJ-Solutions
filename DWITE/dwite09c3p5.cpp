//https://dmoj.ca/problem/dwite09c3p5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t = 5;
    while(t--){
        int n; cin>>n;
        vector<vector<int>>adj(n+1);
        vector<int>colour(n+1);
        for(int i=1;i<=n;i++){
            int x, y;
            cin>>x>>y;
            if(x==y)continue;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for(int c=1;c<=4;c++){
            int mx = 0;
            vector<int>ans;
            for(int i=1;i<(1<<n);i++){
                vector<int>temp;
                bool good = true;
                for(int j=0;j<n;j++){
                    if((1<<j)&i && !colour[j+1]){
                        temp.push_back(j+1);
                    }   
                }

                for(auto from: temp){
                    for(auto to: adj[from]){
                        auto it = find(temp.begin(), temp.end(), to);
                        if(it!=temp.end())good = false;
                        
                    }
                }
                if(good && temp.size()>mx){
                    mx = temp.size();
                    ans = temp;
                }
            }
            for(int x: ans){
                colour[x] = 1;
            }
            if(count(colour.begin(), colour.end(), 1)==n){
                cout<<c<<"\n";
                goto nxt;
            }
        }
        cout<<0<<"\n";

        nxt:;


    }

    return 0;
}