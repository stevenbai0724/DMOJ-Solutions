//https://dmoj.ca/problem/set
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;cin>>n;
    set <int, greater <int>> s1;

    for(int i =0; i<n;i++){
        int x; cin>>x;
        s1.insert(x);
    }
    cout<<s1.size();



    return 0;
}