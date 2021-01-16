//https://dmoj.ca/problem/dwite11c4p2
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    for(int t=1;t<=5;t++){
        int n;cin>>n;

        vector<int>primes(10000);
        vector<string>ans;
        for(int i=n;i>=2;i--){
            int num = i;
            for(int j=2;j*j<=i;j++){
                while(num%j==0){
                    num/=j;
                    primes[j]++;
                }
            }
            if(num>=2)primes[num]++;
        }    
        for(int i=1;i<10000;i++){
            if(primes[i]!=0){
                string temp = to_string(i)+"^"+to_string(primes[i]);
                ans.push_back(temp);
            }
        }
        
        cout<<ans[0];
        ans.erase(ans.begin());
        for(auto x: ans){
            cout<<" * "<<x;
        }
        cout<<"\n";

    }
    
    return 0;
}