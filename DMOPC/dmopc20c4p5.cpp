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

    int n, k;

    cin>>n>>k;

    for(int i=0;i<(1<<n);i++){
        vector<int>arr(n*2+1,1);

        for(int j=0;j<n;j++){
            if((1<<j)&i){
                arr[j+1] = -1;
            }
        }

        for(int j=n+1;j<=(2*n);j++){
            arr[j] = arr[j-n];
        }
        int sum = 0;

        for(int j=1;j<=n;j++){
            int p = 1;
            for(int m=j; m<j+k;m++){
                p*=arr[m];
            }
            sum+=p;
        }

        if(sum==0){
            for(int i=1;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<arr[n]<<"\n";
            return 0;
        }

    }
    cout<<0<<"\n";
  
    return 0;
}