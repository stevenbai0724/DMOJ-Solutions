//https://dmoj.ca/problem/mec16p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string s, t;
    cin>>s>>t;

    s += s;

    for(int i=0;i<=n;i++){
        if(s.substr(i,n)==t){
            if(i<=(ceil)(n/2.0)){
                cout<<"L"+to_string(i);
                return 0;
            }
            else{
                cout<<"R"+to_string(n-i);
                return 0;
            }
        }
    }
    cout<<-1<<"\n";

    return 0;
 
}