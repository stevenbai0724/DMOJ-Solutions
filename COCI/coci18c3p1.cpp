//https://dmoj.ca/problem/coci18c3p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    int ans = 0;
    vector<char>arr{'H','O','N','I'};
    int cur = 0;
    int count = 0;

    for(int i=0;i<s.length();i++){
        if(s[i]==arr[cur]){
            cur = (cur+1)%4;
            count++;
        }
    }
    cout<<count/4<<"\n";
   
    return 0;

}