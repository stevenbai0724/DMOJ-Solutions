//https://dmoj.ca/problem/dmopc14c4p3
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; //l,d
    cin>>n>>m;
    vector<vector<int>>arr(m, vector<int>(n));
    vector<vector<int>>dp(m, vector<int>(n));

    for(int i =0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int endx, endy;
    cin>>endx>>endy;
    vector<int>changeX{-1, 0,0};
    vector<int>changeY{0,-1,1};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = (int)1e9;
        }
    }
    dp[0][0] = arr[0][0];

    for(int t = 0; t<4;t++){
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;

                for(int k = 0;k<3;k++){
                    int newx = i + changeX[k];
                    int newy = j + changeY[k];
                    if(newy>=0 && newy<n && newx>=0 && newx<m){
                        dp[i][j] = min(dp[newx][newy]+arr[i][j], dp[i][j]);
    
                    }
                }
            }
        }
    }
    cout<<dp[endy][endx];

    return 0;
}