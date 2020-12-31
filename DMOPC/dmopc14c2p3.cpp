//https://dmoj.ca/problem/dmopc14c2p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    int sum = 0;
    vector<int>arr(n);
    vector<int>arr2(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end(), greater<int>());

    for(int i=0;i<n;i++){
        sum+= arr[i]*arr2[i];
    }
    cout<<sum;

    return 0;
}