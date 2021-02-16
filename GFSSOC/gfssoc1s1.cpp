//https://dmoj.ca/problem/gfssoc1s1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<pair<int, int>>arr(n);


    for(int i=0;i<n;i++){
        int t; cin>>t;
        int p = 1;
        while(t--){
            int x; cin>>x;
            p*=x;
        }
        arr[i] = {p,i};
    }
    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    for(int i=0;i<3;i++){
        cout<<arr[i].second+1<<"\n";
    }

    return 0;
}