//https://dmoj.ca/problem/dmopc18c5p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int r = 1;
    int mx = 0;
    int sum = arr[1];

    for(int i=1;i<=n;i++){
        sum-=arr[i-1];
        r = max(r, i);
        while(r<n && sum+arr[r+1]<m){
            r++;
            sum += arr[r];
        }
        if(sum<m)mx = max(mx, r-i+1);
    }
    cout<<mx<<"\n";



    return 0;
}