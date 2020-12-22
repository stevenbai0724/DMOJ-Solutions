#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    int ans = 0;
    vector<vector<int>>arr(1e6+5);

    for(int i=1;i<=n;i++){
        int x; cin>>x;

        arr[x].push_back(i);

    }
    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;

        if(arr[a].empty() || arr[b].empty()) continue;
        
        int lower = arr[a].at(0);
        int higher = arr[b].at(arr[b].size()-1);

        ans = max(ans, higher-lower+1);

    }
    cout<<ans;
    return 0;
}
