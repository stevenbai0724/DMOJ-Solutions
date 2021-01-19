//https://dmoj.ca/problem/bts18p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, t;
    cin>>n>>t;
    int sum = 0;
    priority_queue<int>q;
    while(n--){
        int x; cin>>x;
        q.push(x);
    }
    while(t--){
        int cur = q.top();
        q.pop();
        sum+=cur;
        if(cur==0)continue;
        q.push(cur-1);
    }
    cout<<sum<<"\n";
    return 0;
}