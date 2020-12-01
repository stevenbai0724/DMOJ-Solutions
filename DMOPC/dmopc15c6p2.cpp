//https://dmoj.ca/problem/dmopc15c6p2
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin>>n;
    double sum = 0;

    for(int i =0;i<n;i++){
        double x; cin>>x;
        sum+=x;
        sum = fmod(sum, 360);
    }
    cout<<setprecision(15)<<sum;
    return 0;
}