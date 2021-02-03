//https://dmoj.ca/problem/tle16c6s1
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t; cin>>t;
    map<string, int>m;
    for(int i=1;i<=t;i++){
        string s; cin>>s;
        m[s] = i;
    }
    int n; cin>>n;
    vector<pair<int,int>>order; //preference number, problem number
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        order.push_back({m[s], i});
    }
    sort(order.begin(), order.end());
    for(auto p : order){
        cout<<p.second<<"\n";
    }
    
    
    
    return 0;
}
