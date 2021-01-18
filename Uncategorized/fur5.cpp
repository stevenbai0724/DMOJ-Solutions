//https://dmoj.ca/problem/fur5
#include <bits/stdc++.h>
using namespace std;
#define int long long

void hanoi(int n, char a, char b, char c){
    if(n==1) {
        cout<<a<<c<<"\n";
        return;
    }
    hanoi(n-1, a, c, b);
    cout<<a<<c<<"\n";
    hanoi(n-1, b, a, c);
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    hanoi(n, 'A', 'B', 'C');
    
    return 0;
}