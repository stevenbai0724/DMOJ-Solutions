//https://dmoj.ca/problem/wac5p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    set<int>s;
    vector<int>freq(1e6+1);

    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.insert(x);
        freq[x]++;
    }
    int count = 0;
    auto it = s.end();
    int cost = 0;

    while(true){
        it--;
        if(freq[*it]-count>0){
            cost+= *it * (freq[*it]-count);
            count+=freq[*it]-count;
        }
        if(it==s.begin())break;
        
    }
    cout<<cost<<"\n";

    
    return 0;
}