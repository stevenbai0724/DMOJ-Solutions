//https://dmoj.ca/problem/tsoc15c2p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;

    vector<vector<char>>arr(n+1, vector<char>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] = '*';
        }
    }
    int indent = n/2;
    int space = 2;
    for(int i=2;i<=n/2+1;i++){
        
        for(int j=1;j<=space-1;j++){
            arr[i][indent+j] = ' ';
        }
        space+=2;
        indent--;
    }
    
    for(int i=n/2+2;i<=n;i++){
        arr[i] = arr[n-i+1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }




    return 0;
}