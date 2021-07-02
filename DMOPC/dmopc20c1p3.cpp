//https://dmoj.ca/problem/dmopc20c1p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    vector<int>s(n+1);
    vector<int>p(n+1);
    vector<int>psa(n+1);
    vector<int>ssa(n+1);
    int ans = (int)1e18;
    for(int i =1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i =2; i<=n; i++){
        if(arr[i]<arr[i-1]+p[i-1]){
            p[i] = arr[i-1]+p[i-1]-arr[i];
        }
    }
    for(int i =n-1; i>=1; i--){
        if(arr[i]<arr[i+1]+s[i+1]){
            s[i] = arr[i+1]+s[i+1]-arr[i];
        }
    } 
    int sum1 = 0;
    int sum2 = 0;
    for(int i =1; i<=n;i++){
        sum1+= p[i];
        psa[i] =sum1;
    }
    for(int i =n;i>=1; i--){
        sum2+= s[i];
        ssa[i] = sum2;
    }
    for(int i =1;i<n; i++){
        ans = min(ans, psa[i] +ssa[i+1]);
    }

    cout<<ans;
    return 0;
}