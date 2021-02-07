//https://dmoj.ca/problem/dmopc15c4p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==0){
            cout<<"NOT LETHAL\n";
            continue;
        }
        int sum = 0;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        int h, m;
        cin>>h>>m;

        for(int i=1;i<(1<<n);i++){
            int temp = 0;
            for(int j=0;j<n;j++){
                if((1<<j)&i){
                    temp+=arr[j];
                }
            }
            if(temp>=m && sum-temp >=h){
                cout<<"LETHAL\n";
                goto nxt;
            }
        }
        cout<<"NOT LETHAL\n";
        nxt:;

    }


    return 0;
}