//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int k, d;
    cin>>k>>d;

    int mn = 1e18;
    bool zero = false;

    for(int i=1;i<=d;i++){
        int x; cin>>x;
        if(x==0){
            zero = true;
        }
        else mn = min(mn, x);
    }
    if(mn==1e18){
        cout<<-1<<"\n";
        return 0;
    }

    if(zero && k>=3){
        cout<<mn;
        for(int i=1;i<=k-2;i++){
            cout<<0;
        }
        cout<<mn<<"\n";
        return 0;
    }
    else {
        for(int i=1;i<=k;i++){
            cout<<mn;
        }
        cout<<"\n";
    }

    return 0;
}