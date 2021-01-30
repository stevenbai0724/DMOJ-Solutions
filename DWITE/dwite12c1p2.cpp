//https://dmoj.ca/problem/dwite12c1p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 5;
    while(t--){
        double n, m; //* .
        cin>>n>>m;
        double sum = n+m;

        int star, dot;

        star = floor(n/sum *10);
        dot = 10 - star;

        for(int i=1;i<=star;i++){
            cout<<"*";
        }
        for(int i=1;i<=dot;i++){
            cout<<".";
        }
        cout<<"\n";

    }

    return 0;
 
}