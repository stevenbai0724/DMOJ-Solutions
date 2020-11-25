//https://dmoj.ca/problem/dmopc14c5p1
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    double pi = 3.14159;
    double r, h;
    cin >>r>>h;
    double ans = (pi*r*r*h)/3;

    cout<<ans;
    
    return 0;
}