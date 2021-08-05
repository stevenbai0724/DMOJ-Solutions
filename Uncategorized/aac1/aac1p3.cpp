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
    
    int n, x;
    cin>>n>>x;

    if(n%2 != x%2){
        cout<<-1<<"\n";
        return 0;
    }


        int cnt = (n-x)/2;

        for(int i=1;i<=n;i++){
            if(i&1 && cnt>0){
                cout<<1;
                cnt--;
            }
            else{
                cout<<0;
            }
            if(i<n)cout<<" ";
        }

        cout<<"\n";

    return 0;
}