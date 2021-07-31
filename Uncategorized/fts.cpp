//https://dmoj.ca/problem/fts
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ans+=2;
            int j = i;
            while(j<n-1 && s[j+1]=='1')j++;

            i = j;
        }
    }
    if(s[0] == '1')ans--;

    cout<<ans<<"\n";



    return 0;
}