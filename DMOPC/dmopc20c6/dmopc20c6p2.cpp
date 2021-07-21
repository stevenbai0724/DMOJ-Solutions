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
        cntA += (a[i]==1);
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        cntB += (b[i]==1);
    }
    if(cntB!=cntA){
        cout<<-1<<"\n";
        return 0;
    }


    vector<int>aInd;
    vector<int>bInd;

    for(int i=1;i<=n;i++){
        if(a[i]==0)aInd.push_back(i);
        if(b[i]==0)bInd.push_back(i);
    }



    

    return 0;
}