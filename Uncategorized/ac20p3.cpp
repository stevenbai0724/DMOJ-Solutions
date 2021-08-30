//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; 
    cin>>n>>m;
    string s, t;
    cin>>s>>t;

    vector<vector<int>>suf(26, vector<int>(n+1));
    vector<vector<int>>ind(26);
    vector<int>inc(26);
    for(int i=0;i<n;i++){
        ind[s[i]-97].push_back(i);
    }

    for(int i=0;i<26;i++){
        int c = i+97;
        for(int j=n-1;j>=0;j--){
            suf[i][j] = suf[i][j+1];
            suf[i][j] += c==s[j];
        }
    }
    int ans = 0;
    int loop = 0;
    for(int i=0;i<m;i++){
        int pos = ans%n;
        int cur = t[i]-97;

        if(ind[cur].empty()){
            cout<<-1<<"\n";
            return 0;
        }
        if(suf[cur][pos]==0){
            loop++;
            auto it = lower_bound(ind[cur].begin(), ind[cur].end(), 0);
            ans = n*loop + *it;
            fill(inc.begin(), inc.end(), 0);
        }
        else{
            auto it = lower_bound(ind[cur].begin()+inc[cur], ind[cur].end(), pos);
            ans = n*loop + *it;
            inc[cur]++;
        }

    }
    cout<<ans+1<<"\n";



    return 0;
}