//https://dmoj.ca/problem/dmopc20c7p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<pair<int, int>>arr(2*n + 1);

    for(int i=1;i<=2*n;i++){
        int x; cin>>x;
        arr[i] = {x, i};
    }
    sort(arr.begin(), arr.end());

    int cnt = 0;
    vector<pair<int, int>>ans;

    for(int i=1;i<=n;i++){
        ans.push_back({arr[i].second, arr[i+n].second});
        if(arr[i].first!=arr[i+n].first)cnt++;
    }

    cout<<cnt<<"\n";

    for(auto p: ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }


    return 0;
}