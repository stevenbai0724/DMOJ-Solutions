//https://dmoj.ca/problem/primefactor
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

  
    int t; cin>>t;

    while(t--){
        int n; cin>>n; 

        if(n==1){
            cout<<"\n";
            continue;
        }
        
        for(int i =2;i*i<=n;i++){
            while(!(n%i)){
                cout<<i<<" ";
                n/=i;
            }
        }
        if(n>=2)cout<<n;
        cout<<"\n"; 
    }



    return 0;

}