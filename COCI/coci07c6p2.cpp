//https://dmoj.ca/problem/coci07c6p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, l; cin>>n>>l;
    vector<int>arr(n+1);
    vector<pair<int, int>>cycle(n+1);
    int count = 0;
    for(int i=1;i<=n;i++){
        int d,r,g;
        cin>>d>>r>>g;
        arr[i] = d;
        cycle[i] = {r,g};
    }
    for(int i=1;i<=n;i++){
        count += arr[i]-arr[i-1];
        int sum = cycle[i].first+cycle[i].second;
        if(count%sum <cycle[i].first){
            count+= cycle[i].first-(count%sum);
        }
    }
    count+=l-arr[n];
    cout<<count;


    
    return 0;
}