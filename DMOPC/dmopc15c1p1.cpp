//https://dmoj.ca/problem/dmopc15c1p1
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string name = "";
    int ans = 0;

    for(int i =1;i<=n;i++){
        string s; cin>>s;
        double d; cin>>d;
        d*=100;
        int num = d;

        if(num>=ans){
            name = s;
            ans = num;
        }
        
    }
    cout<<name;

    return 0;
}
