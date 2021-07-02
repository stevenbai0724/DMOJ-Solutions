//
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> prefix(vector<int>a){
    int sum = 0;
    int i = 0;
    vector<int>psa(a.size());
    for(auto x: a){
        sum+= x;
        psa[i] = sum;
        i++;
    }
    return psa;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k, x;
    cin>>n>>m>>k>>x;

    vector<int>freq(n);
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>freq[i];
        arr[i] = i;
    }
    vector<int>temp(n+1);
    for(int i=1;i<=n;i++){
        temp[i] = freq[i-1];
    }
    vector<int>psa = prefix(temp);
    //if psa[]


    return 0;
}