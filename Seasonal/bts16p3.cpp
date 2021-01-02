//https://dmoj.ca/problem/bts16p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int total = n;
    int cur;
    int count = 0;
    vector<int>arr;

    string s;cin>>s;
    cur = (int)s[0];
    for(int i =2;i<=n;i++){
        string t; cin>>t;
        if((int)t[0] == cur ||(int)t[0]-32==cur ||(int)t[0]+32==cur){
            count++;
            if(i==n && count>0)arr.push_back(count);
            continue;
        }
        else{
            arr.push_back(count);
            count = 0;
            cur = (int)t[0];
        }
    }
    for(int i =0; i<arr.size();i++){
        total += ((arr.at(i) + 1)*(arr.at(i)))/2;
    }
    cout<<total%1000000007;


    return 0;
}