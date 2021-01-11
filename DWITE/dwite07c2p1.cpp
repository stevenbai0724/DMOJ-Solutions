//https://dmoj.ca/problem/dwite07c2p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<bool>prime(40, true);
    vector<int>arr;
    vector<bool>ans(2000);
    for(int i=2;i*i<=40;i++){
        if(prime[i]){
            for(int j=2;j*i<=40;j++){
                prime[i*j] = false;
            }
        }
    }
    for(int i=2;i<=40;i++){
        if(prime[i]){
            arr.push_back(i);
        }
    }
    
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            ans[arr[i]*arr[j]] = true;
        }
    }
    
    for(int i=1;i<=5;i++){
        int x; cin>>x;
        if(ans[x])cout<<"semiprime\n";
        else cout<<"not\n";
    }

    
    return 0;
}
