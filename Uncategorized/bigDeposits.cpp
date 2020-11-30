//https://dmoj.ca/problem/bdep
#include <bits/stdc++.h>
using namespace std;
#define int long long
int p, y, t; //interest, years, goal;
bool good(int x){

    int total =0;

    for(int i =1;i<=y;i++){
        total = (total + x) * (100 + p) / 100;
        if(total>=t) return true;

    }
    return total>=t;

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>p>>y>>t;

    int l = 0;
    int r = t;

    while(l+1<r){
        int m = (l+r)/2;

        if(good(m)) r= m;
        else l = m;
    }
    cout<<r;

    return 0;
}