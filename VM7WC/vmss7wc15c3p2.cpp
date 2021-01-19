//https://dmoj.ca/problem/vmss7wc15c3p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum = 0;
    sort(arr.begin(), arr.end(), greater<int>());

    for(int i=0;i<k;i++){
        if(arr[i]<0)break;
        sum+=arr[i];
    }
    
    cout<<sum;
    return 0;
}