//https://dmoj.ca/problem/dmopc15c1p4
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin>>n>>x;
    int sum = 0;
    vector<bool>prime(n+1, true);

    prime[0] = false;
    prime[1] = false;

    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=2;j*i<=n;j++){
                prime[i*j] = false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]){
            sum += ((n-i)/x) + 1;
            if(n-i-1>=0)sum += ((n-i-1)/x)+ 1;
        }
    }
    cout<<sum;
    return 0;
}