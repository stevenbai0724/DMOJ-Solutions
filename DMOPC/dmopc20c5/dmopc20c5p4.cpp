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
    
    int n, m;
    cin>>n>>m;

    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<string>rows(n+1);
    vector<string>cols(m+1);

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
        rows[i] = " " + s;
    }
    for(int j=1;j<=m;j++){
        string temp = " ";
        for(int i=1;i<=n;i++){
            temp+=arr[i][j];
        }
        cols[j] = temp;
    }
    int ans = 0;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){  
            
            for(int l=2;l+i-1<=n;l++){
                for(int k=2;k+j-1<=m;k++){
                    
                    string r1 = rows[i].substr(j,k);
                    string r2 = rows[i+l-1].substr(j,k);

                    string c1 = cols[j].substr(i,l);
                    string c2 = cols[j+k-1].substr(i,l);

                    ans+=(c1==c2 && r1==r2);


                }
            }
          
        }
    }

    cout<<ans<<"\n";


  

    return 0;
}