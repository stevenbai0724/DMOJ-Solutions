#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x, y, t;
    cin >> x >> y>> t;

    int l = floor(x/t);
    int w = floor(y/t);
    cout<<l*w<<"\n";
    return 0;
}