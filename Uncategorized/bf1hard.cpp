//https://dmoj.ca/problem/bf1hard
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<"\n";
    }

    return 0;
}
