//https://dmoj.ca/problem/phantom1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<bool>prime(501, true);
    prime[0] = false;
    prime[1] = false;

    for(int i =2;i*i<=500;i++){
        if(prime[i]){
            for(int j=2;j*i<=500;j++){
                prime[i*j] = false;
            }
        }
    }

    int n; cin>>n;
    for(int i =1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        int ans = 0;

        for(int j=a; j<b;j++){
            if(prime[j]) ans++;
        }
        cout<<ans<<"\n";
    }


    

    return 0;
}