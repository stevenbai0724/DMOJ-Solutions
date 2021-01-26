//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    int count = 0; //number of on lights
    int ans = 1e9;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==1)count++;
    }

    if(count==0){
        for(int i=1;i<=m;i++){
            int bruh; cin>>bruh;
        }
        cout<<0<<"\n";
        return 0;
    }
    for(int i=1;i<=m;i++){

        int x; cin>>x;
        if(arr[x]==1){
            arr[x] = 0;
            count--;
        }
        else if(arr[x]==0){
            arr[x] = 1;
            count++;
        }

        if(count<=i)ans = min(ans, i);
    }
    if(ans==1e9){
        cout<<count<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
    

    return 0;

}