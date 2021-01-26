//https://dmoj.ca/problem/valentines19j1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
   
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n<1000)cout<<"Newbie\n";
        else if(n<1200)cout<<"Amateur\n";
        else if(n<1500)cout<<"Expert\n";
        else if(n<1800)cout<<"Candidate Master\n";
        else if(n<2200)cout<<"Master\n";
        else if(n<3000)cout<<"Grandmaster\n";
        else if(n<4000)cout<<"Target\n";
        else cout<<"Rainbow Master\n";
    }

   
    return 0;

}