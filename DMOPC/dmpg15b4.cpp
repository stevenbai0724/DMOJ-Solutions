//https://dmoj.ca/problem/dmpg15b4
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>neg, pos;
    int ans = 1;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x>0){
            pos.push_back(x);
            ans*=x;
        }
        if(x<0)neg.push_back(x);

    }
    sort(neg.begin(), neg.end());
    if(neg.size()==0){
        if(!pos.empty()){
            cout<<ans;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(neg.size()==1){
        if(!pos.empty()){
            cout<<ans;
            return 0;
        }
        if(n>1){
            cout<<0;
            return 0;
        }
        cout<<neg[0];
        return 0;
    }

    if(neg.size()&1){
        neg.pop_back();
    }
    for(auto x: neg){
        ans *= x;
    }
    cout<<ans;
    return 0;
}