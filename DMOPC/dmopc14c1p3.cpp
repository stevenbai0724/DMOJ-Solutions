//https://dmoj.ca/problem/dmopc14c1p3
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    double count, sum;
    count =n;

    for(int i=0;i<n;i++){
        int x; cin>>x;
        sum+=x;
    }
    int m; cin>>m;
    for(int i =0;i<m; i++){
        count += 1.0;
        int x; cin>>x;
        sum+=x;
        cout<<sum/count<<"\n";

    }
    return 0;
}
