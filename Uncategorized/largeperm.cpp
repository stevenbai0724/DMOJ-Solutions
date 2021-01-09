//https://dmoj.ca/problem/largeperm
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+1);
    vector<int>index(n+1);
    
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        arr[i] = x;
        index[x] = i;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==n-i+1)continue;
        if(k==0)break;
        else{
            k--;
            int temp = arr[i];
            index[temp] = index[n-i+1];
            arr[i] = arr[index[n-i+1]];
            arr[index[n-i+1]] = temp;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}