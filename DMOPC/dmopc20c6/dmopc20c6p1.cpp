//https://dmoj.ca/problem/dmopc20c6p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int>arr(2*(n+1));

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i+n] = arr[i];
    }

    if(n==2){
        cout<<abs(arr[1]-arr[2])<<" "<<abs(arr[1]-arr[2])<<"\n";
        return 0;
    }
    vector<int>psa(2*(n+1));
    int sum = 0;
    for(int i=1;i<=2*n;i++){
        sum += arr[i];
        psa[i] = sum;
    }
    int split = 1;
    int mn = 1e18;  
    for(int i=1;i<n;i++){
        int compare = abs((psa[n]-psa[i]) - psa[i]);
        if(compare<mn){
            mn = compare;
            split = i;
        }
    }

    int left = psa[split];
    int right = (psa[n]-psa[split]);
    int diff = abs(left-right);
    cout<<diff<<" ";
    
    
    for(int i=2;i<=n;i++){
        split = max(split, i);
        left = psa[split]-psa[i-1];
        right = psa[i+n-1]-psa[split];

 
        diff = abs(left-right);

        while(split<(2*n) && abs((left + arr[split+1])-(right - arr[split+1]) < diff)){
            split++;
            left = psa[split]-psa[i-1];
            right = psa[i+n-1]-psa[split];
            diff = abs(left-right);
            
        }
        
        cout<<diff;
        if(i<n)cout<<" ";
       
    }
    cout<<"\n";

    

    return 0;
}