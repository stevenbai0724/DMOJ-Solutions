//https://dmoj.ca/problem/dmopc17c5p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);


    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            cout<<"DNE\n";
            return 0;
        }
    }

    if(n==1){
        int mx = 0;

        for(int i=2;i*i<=arr[1];i++){
            while(arr[1]%i==0){
                arr[1]/=i;
                mx = i;
            }
        }
        if(n>1)mx = n;
        
        cout<<mx<<"\n";
        return 0;
    }
    int gcd = __gcd(arr[1], arr[2]);

    for(int i=3;i<=n;i++){
        gcd = __gcd(gcd, arr[i]);
    }

    if(gcd==1)cout<<"DNE\n";
    else{
    
        int mx = 0;
        for(int i=2;i*i<=gcd;i++){
            while(gcd%i==0){
                gcd/=i;
                mx = i;
            }
        }
        if(gcd>1)mx = gcd;
        cout<<mx<<"\n";
    }




    return 0;
}