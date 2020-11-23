//https://dmoj.ca/problem/dmopc14c2p1
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >>n;

    for(int t = 1; t<=n; t++){
        int d; cin>>d;
        int sum = 0;
        for(int i = 0; i<d; i++){
            int x; cin>>x;
            sum += x;

        }
        if(sum!=0)cout<<"Day "<<t<< ": "<<sum<<"\n";
        else cout<<"Weekend"<<"\n";
    }
    return 0 ;
}