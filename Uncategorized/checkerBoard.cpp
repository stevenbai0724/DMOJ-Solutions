#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<int>>arr(n+1, vector<int>(m+1));
    vector<vector<int>>psa(n+1, vector<int>(m+1));
    vector<vector<int>>psa2(n+1, vector<int>(m+1));

    while (true){
        int r, c, x;
        cin>>r>>c>>x;
        if(r==0)break;

        arr[r][c] = x;
    }
    for(int i = 1;i<=n; i++){
        for(int j=1; j<=m; j++){
            if(((i%2==1&&j%2==1)) || ((i%2==0&&j%2==0))){
                psa[i][j] = psa[i][j-1]-psa[i-1][j-1]+psa[i-1][j]+arr[i][j];
            }
            else psa[i][j] = psa[i][j-1]-psa[i-1][j-1]+psa[i-1][j];
                
        }
    }
    for(int i = 1;i<=n; i++){
        for(int j=1; j<=m; j++){
            if(((i%2==0 && j%2==1)) || ((i%2==1 & j%2==0))){
                psa2[i][j] = psa2[i][j-1]-psa2[i-1][j-1]+psa2[i-1][j]+arr[i][j];
            }
            else psa2[i][j] = psa2[i][j-1]-psa2[i-1][j-1]+psa2[i-1][j];
        }
    }
    while(true){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(a==0)break;
        int ans = 0;
        int x = psa[c][d]-psa[a-1][d]+psa[a-1][b-1]-psa[c][b-1];
        int y = psa2[c][d]-psa2[a-1][d]+psa2[a-1][b-1]-psa2[c][b-1];
   
        if(((a%2==1)&&(b%2==1)) || ((a%2==0)&&(b%2==0) )){
           ans = x-y;
        }
        else ans = y-x;

        cout<<ans<<"\n";
    }
    return 0;
}