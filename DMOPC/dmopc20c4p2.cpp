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

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, k;
    cin>>n>>m>>k;

    gp_hash_table<int, int>rows;
    gp_hash_table<int, int>cols;

    int ans = 0;

    set<int>rowsUsed;
    set<int>colsUsed;

    while(k--){
        int r, c;
        cin>>r>>c;

        rows[r]++;
        cols[c]++;

        rowsUsed.insert(r);
        colsUsed.insert(c);

    }

    queue<int>oddRows;
    queue<int>oddCols;
    for(auto x: rowsUsed){
        if(rows[x]&1)oddRows.push(x);
    }
    for(auto x: colsUsed){
        if(cols[x]&1)oddCols.push(x);
    }
    int a = oddRows.size();
    int b = oddCols.size();

    ans = (min(a,b) + abs(a-b));
    cout<<ans<<"\n";

    for(int i=0;i<min(a,b);i++){
        cout<<oddRows.front()<<" "<<oddCols.front()<<"\n";
        oddRows.pop();
        oddCols.pop();
    }
    while(!oddRows.empty()){
        cout<<oddRows.front()<<" "<<1<<"\n";
        oddRows.pop();
    }
    while(!oddCols.empty()){
        cout<<1<<" "<<oddCols.front()<<"\n";
        oddCols.pop();
    }
    



    return 0;
}