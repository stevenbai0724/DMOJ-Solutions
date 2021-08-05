//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    queue<int>big, small;

    for(int i=1;i<=n;i++){
        small.push(arr[i]);
        big.push(arr[n-i+1]);
    }
    vector<int>ans;
    string st = "";
    for(int i=1;i<=(n/2) * 2;i++){
        if(i&1){
            ans.push_back(small.front());
            small.pop();
            st += 'B';
        }
        else{
            ans.push_back(big.front());
            big.pop();
            st += 'S';
        }
    }
    if(n&1){
        ans.push_back(arr[n/2+1]);
        st += 'E';
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
    cout<<st<<"\n";

    return 0;
}