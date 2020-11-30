#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);   

    int n; cin>>n;
    vector<int>arr(n+2);
    vector<int>index;
    for(int i =1;i<=n;i++){
        int x; cin>>x;
        arr[i] = (int)1e9 *(x%10) + x;
    }
    sort(arr.begin(),arr.begin()+n+1);

    for(int i=1;i<=n;i++){
        arr[i]%=(int)1e9;
    }
    index.push_back(1);
    for(int i =1;i<n;i++){
        if(arr[i]%10 != arr[i+1]%10){
            index.push_back(i+1);
        }
    }
    index.push_back(n+1);
    for(int i =0;i<index.size()-1;i++){
        sort(arr.begin()+index.at(i), arr.begin()+index.at(i+1), greater<int>());

    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}