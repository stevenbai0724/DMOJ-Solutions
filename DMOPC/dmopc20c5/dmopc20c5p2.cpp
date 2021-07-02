//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
int rise, run;

bool good(double r, double c){
    
    double north = r*run/rise;
    double south = (r-1)*run/rise;
    double west = (c-1)*rise/run;
    double east = (c)*rise/run;

    bool case1 = ((c-1)<=north) && (north<=c);
    bool case2 = ((c-1)<=south) && (south<=c);
    bool case3 = ((r-1)<=west) && (west<=r);
    bool case4 = ((r-1)<=east) && (east<=r);

    return (case1 || case2 || case3 || case4);
}
bool move(double r, double c){
    double rs = (double)rise/(double)run * (c);

    if(r==floor(rs))return true;
    else return false;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    

    int n, m;
    cin>>n>>m;

    rise = n;
    run = m;

    for(int i=2;i<=max(rise,run);i++){
        while(i<=min(rise,run)){
            if(!(rise%i) && !(run%i)){
                rise/=i;
                run/=i;
            }
            else break;
        }
    }
    vector<pair<int, int>>ans;

    int r = 1;
    int c = 1;

    while(true){


        ans.push_back({r,c});

        if(r==rise && c==run)break;

        if(good(r, c+1))c++;
        else r++;

    }

    sort(ans.begin(), ans.end());
    /*

    }*/

    int cur = ans.size();

    for(int i=0;i<cur;i++){
        int curr = ans[i].first;
        int curc = ans[i].second;

        for(int j=1;j<(n/rise);j++){
            ans.push_back({curr+(j*rise), curc+(j*run)});
        }
    }
    sort(ans.begin(), ans.end());

    cout<<ans.size()<<"\n";

   

    for(auto p: ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    
    


  

    return 0;
}