//https://dmoj.ca/problem/coci12c6p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<string>arr{".",".","ABC","DEF","GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    int ans = 0;
    string s; cin>>s;

    for(int i=0;i<s.length();i++){
        string c ="";
        c+=s[i];

        for(int j=0;j<10;j++){
            size_t found = arr[j].find(c);
            if(found!=string::npos){
                ans+=j+1;
                break;
            }
        }

    }
    cout<<ans<<"\n";

    return 0;
}