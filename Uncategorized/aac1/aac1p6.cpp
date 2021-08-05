//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;

    vector<pair<int, int>>arr(n);

    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        arr[i] = {a,b};
    }
    int ans = 1;
    for(int i=1;i<(1<<n);i++){
        
        vector<pair<int, int>>temp;

        for(int j=0;j<n;j++){
            if((1<<j)&i)temp.push_back(arr[j]);
        }
        sort(temp.begin(), temp.end());

        int m = temp.size();

        if(m==1)goto nxt;

        if(temp[1].first-temp[0].first<temp[0].second)goto nxt;
        if(temp[m-1].first-temp[m-2].first<temp[m-1].second)goto nxt;

        for(int j=1;j<m-1;j++){
            int a = temp[j-1].first;
            int b = temp[j].first;
            int c = temp[j+1].first;
            int dis = temp[j].second;

            if(b-a < dis || c-b < dis)goto nxt;
        }

        ans = max(ans, m);

        nxt:;



    }

    cout<<ans<<"\n";


    return 0;
}