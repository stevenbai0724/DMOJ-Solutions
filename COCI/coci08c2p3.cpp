//https://dmoj.ca/problem/coci08c2p3
//perket
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int c = 1e9+3;
    int ans = 1e18;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int s, b;
        cin>>s>>b;
        arr[i] = s*c +b;
    }
    int curS = 1;
    int curB = 0;
    for(int i=0;i<n;i++){
        curS *= arr[i]/c;
        curB += arr[i]%c;
        ans = min(ans, abs(curB-curS));
    }
    while(next_permutation(arr.begin(), arr.end())){
        curS = 1;
        curB = 0;
        for(int i=0;i<n;i++){
            curS*=arr[i]/c;
            curB+=arr[i]%c;
            ans = min(ans, abs(curB-curS));
        }
    }
    cout<<ans;

    return 0;
}