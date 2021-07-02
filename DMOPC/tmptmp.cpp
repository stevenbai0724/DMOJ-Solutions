//https://dmoj.ca/problem/dmopc20c3p2

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int m, n, k;
    cin>>m>>n>>k;

    vector<vector<int>>arr(m+1, vector<int>(n+1));
    
    gp_hash_table<int, int>mp [21]; 
    int ans = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            arr[i][j] =x;
            mp[j][x] = i; //x note, jth beat, ith singer
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<n;j++){
            int dx = arr[i][j]+k;

            int singer = mp[j][dx];
            if(singer==0)continue;
            if(arr[singer][j]-arr[i][j] ==k && arr[singer][j+1]-arr[i][j+1]==k)ans++;
        }
    }
    cout<<ans<<"\n";
 
}