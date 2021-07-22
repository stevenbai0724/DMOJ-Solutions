//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    
    vector<int>a(n+1);
    vector<int>b(n+1);

    int cntA = 0;
    int cntB = 0;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)cntA++;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]==1)cntB++;
    }
    if(cntB!=cntA){
        cout<<-1<<"\n";
        return 0;
    }

    vector<int>aInd{-1}, bInd{-1};
    
    for(int i=1;i<=n;i++){
        if(a[i]==0)aInd.push_back(i);
        if(b[i]==0)bInd.push_back(i);
    }

    for(int i=1;i<=aInd.size();i++){
        if(aInd[i]<bInd[i]){
            cout<<-1<<"\n";
            return 0;
        } 
    }
    vector<pair<int, int>>segs; //consecutive segments of 0's in b[]

    for(int i=1;i<=n;i++){
        if(b[i] == 0){
            int j = i;
            while(j<n && b[j+1]==0) j++;

            segs.push_back({i,j});
            i = j;
        }
    }
    vector<pair<int, int>>ans;
    int cur = 0; //we are brushing until the cur-th 0 in a[], i.e aInd[cur]
    for(auto x: segs){
        int l = x.first;
        int r = x.second;
        int len = r-l + 1;

        cur += len;


        if(aInd[cur]==bInd[cur]){
            continue;

        }
        ans.push_back({l,aInd[cur]});

    }

    cout<<ans.size()<<"\n";
    for(auto x: ans){
        cout<<x.first<<" "<<x.second<<"\n";
        sort(a.begin()+x.first, a.begin()+ x.second + 1);
    }
     assert(a==b);

    

    return 0;
}