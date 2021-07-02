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
    vector<int>arrA(n+1);
    vector<int>arrB(n+1);
    vector<int>psaA(n+1);
    vector<int>psaB(n+1);
    int cntA = 0;
    int cntB = 0;

    for(int i=1;i<=n;i++){
        cin>>arrA[i];
        if(arrA[i]==1)cntA++;
        psaA[i] = cntA;
    }
    for(int i=1;i<=n;i++){
        cin>>arrB[i];
        if(arrB[i]==1)cntB++;
        psaB[i] = cntB;
    }
    if(cntA!=cntB){
        cout<<-1<<"\n";
        return 0;
    }
    vector<pair<int, int>>ans;

    for(int i=n;i>=1;i--){
        if(arrB[i] == 1 && arrA[i] == 1)continue;
        if(arrB[i] == 1){
            int j = i;

            while(arrB[j-1]==1 && j>=1) j--;

            int cnt = i-j+1;
            int take = -1;

            for(int k=i;k>=1;k--){
                cnt -= arrA[k];
                arrA[k] = 0;
                if(cnt==0){
                    take = k;
                    break;
                    
                }
            }
            if(cnt!=0){
                cout<<-1<<"\n";
                return 0;
            }

            ans.push_back({take, i});

            i = j;

        }
    }
    cout<<ans.size()<<"\n";

    for(auto p: ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }




    

    return 0;
}