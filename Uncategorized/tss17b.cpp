//https://dmoj.ca/problem/tss17b
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;

    vector<double>arr;

    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;

        arr.push_back(sqrt((x*x)+(y*y)));


    }
    arr.push_back(0);
    sort(arr.begin(), arr.end());

    while(q--){
        int r; cin>>r;

        auto it = upper_bound(arr.begin(), arr.end(), r);

        it--;
        cout<<it-arr.begin()<<"\n";
    }


    return 0;
}