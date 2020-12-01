//https://dmoj.ca/problem/dmopc15c1p5
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int w,h,n;
    cin >> w >> h >> n;
    int ans = 0;
    vector<vector<int>>psa(h+1,vector<int>(w+1));
    vector<vector<int>>arr(h+1,vector<int>(w+1));
    for(int i = 1; i<=h; i++){
        for(int j = 1; j<=w; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i<=h; i++){
        for(int j = 1; j<=w; j++){
            psa[i][j] = psa[i][j-1]-psa[i-1][j-1]+psa[i-1][j]+arr[i][j];
        }
    }

    
    for(int i = 1; i<=h; i++){
        for(int j = 1; j<= w; j++){
            for(int k = 1; k<=w; k++){
                if(k>n)break;
                int c, d;
                if(j+k-1 <=w) d = j+k-1;
                if(j+k-1 >w) d = w;
                if(i+(n/k)-1 <=h) c = i+(n/k)-1;
                if(i+(n/k)-1 >h) c = h;

                ans = max(ans, psa[c][d]-psa[i-1][d]+psa[i-1][j-1]-psa[c][j-1]);

            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
