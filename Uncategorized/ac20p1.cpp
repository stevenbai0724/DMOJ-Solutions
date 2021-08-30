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

    int t; cin>>t;
    while(t--){
        vector<int>arr(3);
        cin>>arr[0];
        cin>>arr[1];
        cin>>arr[2];
        sort(arr.begin(), arr.end());

        if(arr[0]*arr[0] + arr[1]*arr[1]==arr[2]*arr[2]){
            cout<<"R\n";
            continue;
        }
        else if(arr[0]*arr[0] + arr[1]*arr[1]<arr[2]*arr[2]){
            cout<<"O\n";
            continue;
        }
        else cout<<"A\n";


    }


    return 0;
}