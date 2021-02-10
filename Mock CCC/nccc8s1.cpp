//https://dmoj.ca/problem/nccc8s1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define string std::string
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string a, s;
    cin>>a>>s;
    set<string>ans;
    int m = a.length();
    int n = s.length();

    //add to beginning
    for(int i=0;i<m;i++){
        ans.insert(a[i]+s);
    }
    //replace
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            string temp = s;
            temp[j] = a[i];
            ans.insert(temp);
        }
    }
    //add to s[i+1]
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            string temp = "";
            for(int k=0;k<n;k++){
                temp+=s[k];
                if(k==j)temp+=a[i];
            }
            ans.insert(temp);
        }
    }
    //delete
    for(int i=0;i<n;i++){
        string temp = s;
        temp.erase(i,1);
        ans.insert(temp);

    }
    ans.insert(s);
    ans.erase(ans.find(s));
    for(auto x: ans){
        cout<<x<<"\n";
    }

    




    return 0;
}