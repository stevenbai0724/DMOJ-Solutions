#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    vector<int>arr(n+2);
    vector<int>psa(n+2);
    int count = 0;
    for(int i=1;i<=q;i++){
        int a, b; cin>>a>>b;
        arr[a+1]++;
        arr[b+1]--;
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=arr[i];
        psa[i]+=sum;
    }
    for(int i=1;i<=n;i++){
        if(psa[i]==0)count++;
    }
    cout<<count<<" "<<n-count;

    return 0;
}