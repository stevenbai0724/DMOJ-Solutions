//https://dmoj.ca/problem/dmopc15c1p2
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, l, r;
    cin>>n>>l>>r;
    if(r>n){
        cout<<0;
        return 0;
    }
    vector<int>arr(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    for(int i=r-1;i<n;i+=l){
        sum += arr[i];
    }
    cout<<sum;

    return 0;
}