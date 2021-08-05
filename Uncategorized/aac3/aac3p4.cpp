//https://dmoj.ca/problem/aac3p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    gp_hash_table<int, int>mp;

    multiset<int>rows;
    multiset<int>cols;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x==-1)continue;
        rows.insert(x-i);
    }
    for(int i=1;i<=m;i++){
        int y; cin>>y;
        if(y==-1)continue;
        cols.insert(y-i);
    }
    int cnt = 0;
    for(int x: cols){
        mp[x]++;
    }
    for(int x: rows){
        if(mp[x]==0)continue;
        else{
            mp[x]--;
            cnt++;
        }
    }
    
    cout<<cnt<<"\n";


    return 0;
}