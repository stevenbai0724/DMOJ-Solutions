//https://dmoj.ca/problem/geometry1
//area of triangle formed by 3 coordinates is abs((0.5)*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string

double solve(double a, double b, double c, double d){
    double dx = abs(a-c);
    double dy = abs(b-d);
    dy*=dy;
    dx*=dx;
    return sqrt(dy+dx);
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        cout<<abs((0.5)*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))<<" ";
        cout<<solve(x1,y1,x2,y2)+solve(x1,y1,x3,y3)+solve(x2,y2,x3,y3)<<"\n";

    }

    return 0;
}