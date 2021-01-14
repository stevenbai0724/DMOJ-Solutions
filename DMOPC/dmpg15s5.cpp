//https://dmoj.ca/problem/dmpg15s5
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >>n>>m;
    int count = 0;
    vector<vector<bool>>arr(n+2, vector<bool>(n+2));
    vector<vector<bool>>psa(n+2, vector<bool>(n+2));
    
    for(int i =0 ;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        arr[a+1][b+1] = !arr[a+1][b+1];
        arr[a+1][b+d+1] = !arr[a+1][b+d+1];
        arr[a+c+1][b+1] = !arr[a+c+1][b+1];
        arr[a+c+1][b+d+1] = !arr[a+c+1][b+d+1];

    }
    for(int i =1; i<=n;i++){
        for(int j= 1; j<=n;j++){
            psa[i][j] = (arr[i][j]+ psa[i][j-1]-psa[i-1][j-1]+psa[i-1][j])%2;
            count+=psa[i][j];
        }
      
    }
    cout<<count<<"\n";
    return 0;

}