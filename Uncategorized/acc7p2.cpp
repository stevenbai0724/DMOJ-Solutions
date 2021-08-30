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
    
    vector<int>arr;
    int n; cin>>n;
    arr.resize(n+1);

    for(int i=1;i<=n;i++){
        arr[i] = i;
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    while(true){

        int x; cin>>x;
        if(x==0){
            cout<<endl;
            return 0;
        }

        int ind = 0;
        for(int i=1;i<=n;i++){
            if(arr[i]==x)ind = i;
        }
        if(ind == 1){
            int temp = arr[2];
            arr[2] = arr[1];
            arr[1] = temp;
        }
        else{
            int temp = arr[ind-1];
            arr[ind-1] = arr[ind];
            arr[ind] = temp;
        }
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    return 0;
}