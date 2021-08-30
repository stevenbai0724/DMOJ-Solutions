//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    vector<int>arr(1e5+1);

    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr[x]++;
    }
    while(q--){
        int o, x;
        cin>>o>>x;
        if(o==1){
            int times = arr[x];
            arr[x] = 0;
            double num = x;
            double a = floor(num/2.0);
            double b = ceil(num/2.0);
            arr[a]+=times;
            arr[b]+=times;
        }
        else{
            cout<<arr[x]<<"\n";
        }
    }


    return 0;
}