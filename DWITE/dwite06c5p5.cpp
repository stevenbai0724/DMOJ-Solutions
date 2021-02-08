//https://dmoj.ca/problem/dwite06c5p5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

bool check(int x){
    string s = to_string(x);
    int n = s.length();
    string one = "";
    string two = "";

    for(int i=0;i<=(n-1)/2;i++){
        one+=s[i];
    }
    for(int i=n-1;i>=(n/2);i--){
        two+=s[i];
    }
    return two==one;

}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<bool>primes(1e6+1, true);
    vector<bool>dromes(1e6+1);
    vector<int>psa(1e6+1);
    int sum = 0;
    for(int i=2;i*i<=1e6;i++){
        if(primes[i]){
            for(int j=2;j*i<=1e6;j++){
                primes[i*j] = false;
            }
        }
    }
    for(int i=2;i<=1e6;i++){
        dromes[i] = check(i);
    }
    for(int i=2;i<=1e6;i++){
        sum+=(primes[i] && dromes[i]);
        psa[i] = sum;
    }
    int t = 5;
    while(t--){
        int n, m;
        cin>>n>>m;
        cout<<psa[m]-psa[n-1]<<"\n";
    }


    return 0;
}