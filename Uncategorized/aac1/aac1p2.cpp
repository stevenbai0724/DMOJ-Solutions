//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, d, k, x;
    cin>>n>>d>>k>>x;

    priority_queue<int>q;

    for(int i=1;i<=n;i++){
        int num; cin>>num;
        q.push(num);
    }
    int p; cin>>p;


    while(k--){
        double cur = q.top();
        q.pop();

        cur = floor(cur * ((100-x)/100.0));

        q.push(cur);
    }
    
    while(!q.empty()){
        int cur = q.top();
        q.pop();
        if(cur>=p){
            cout<<"NO\n";
            return 0;
        }

    }
    cout<<"YES\n";





    return 0;
}