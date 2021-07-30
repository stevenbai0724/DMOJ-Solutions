//https://dmoj.ca/problem/wc17c2j2
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y, z;
    cin>>a>>b>>c>>x>>y>>z;

    cout<<min(x/a, min(y/b, z/c))<<"\n";
}