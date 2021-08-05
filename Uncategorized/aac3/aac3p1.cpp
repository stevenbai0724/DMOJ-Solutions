//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b, c, d;
    cin>>a>>b>>c>>d;

    if(b>a && d>c){
        cout<<"Go to the department store\n";
    }
    else if(b>a){
        cout<<"Go to the grocery store\n";
    }
    else if (d>c){
        cout<<"Go to the pharmacy\n";
    }
    else cout<<"Stay home\n";


    return 0;
}