//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
int n, m;


int ugly(vector<vector<char>>arr){
    vector<string>rows(n+1);
    vector<string>cols(m+1);

    for(int i=1;i<=n;i++){
        string temp = " ";
        for(int j=1;j<=m;j++){
            temp +=arr[i][j];
        }
        rows[i] = temp;
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
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    

    cin>>n>>m;
    vector<vector<char>>ans;

    int mn = 1e9;

    for(int i=0;i<(1<<(n*m));i++){
        vector<vector<char>>temp(n+1, vector<char>(m+1));

        for(int l=1;l<=n;l++){
            for(int k=1;k<=m;k++){
                temp[l][k] = 'Y';
            }
        }
        int cnt = 0;

        for(int j=0;j<(n*m);j++){
            if((1<<j)&i){
                int num = j+1;

                for(int l=1;l<=n;l++){
                    for(int k=1;k<=m;k++){
                        num--;
                        if(num==0){
                            temp[l][k] = 'B';
                            goto nxt;
                        }

                    }
                }
                nxt:;
            }
        }
        cnt = ugly(temp);

        if(cnt<mn){
            ans = temp;
            mn = cnt;
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }

  

    return 0;
}