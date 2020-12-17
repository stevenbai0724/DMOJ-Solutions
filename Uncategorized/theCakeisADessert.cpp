#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin>>m>>n; //m cols, n rows
    cin>>k;
    vector<vector<int>>arr(n+4,vector<int>(m+2));
    vector<vector<int>>psa(n+2,vector<int>(m+2));
    vector<vector<int>>psa2(n+2, vector<int>(m+1));

    for(int i=0; i<k; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        arr[n-d+1][a]++;
        arr[n-d+1][c+1]--;
        arr[n-b+2][a]--;
        arr[n-b+2][c+1]++;

    }
    
    for(int i =1; i<=n; i++){
        for(int j= 1;j<=m; j++){
            psa[i][j] = psa[i][j-1]-psa[i-1][j-1]+psa[i-1][j] + arr[i][j];
        }
    }
    for(int i =1; i<=n; i++){
        for(int j =1;j<=m; j++){
            psa2[i][j] = psa2[i][j-1]-psa2[i-1][j-1]+psa2[i-1][j]+psa[i][j];
        }
    }
    int p;cin>>p;
    for(int i =0; i<p; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int ans = psa2[n-b+1][c]-psa2[n-d][c]+psa2[n-d][a-1]-psa2[n-b+1][a-1];
        cout<<ans<<"\n";
    }
    return 0;
}