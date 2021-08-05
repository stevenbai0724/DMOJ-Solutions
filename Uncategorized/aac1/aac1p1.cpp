
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    double x, y;
    cin>>x>>y;

    cout<<((x*x > y*y*3.14)?("SQUARE"):("CIRCLE"));
    cout<<"\n";

    return 0;
}