//https://dmoj.ca/problem/mccc1s1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int count = 0;
    bool war = false;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i] && !war){
            war = true;
            count++;
        }
        if(a[i]!=b[i] && war){
            war = false;
        }
    }
    cout<<count;
    return 0;
}
