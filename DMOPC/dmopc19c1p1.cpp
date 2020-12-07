//https://dmoj.ca/problem/dmopc19c1p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x; cin >> x;

    for(int i = 0 ; i<x; i++){
        double n; cin>>n;  //problems
        double a; cin>>a;  //+points for AC
        double b; cin>>b;  //-points for WA
        double t; cin>>t;  // goal score
 
        if(n*a <t){
            cout<<-1<<endl;
            continue;
        }
        int ans = ceil((t + (b*n))/(a+b));
        
        cout<<ans<<"\n";
    
    }
        
    return 0 ;
}