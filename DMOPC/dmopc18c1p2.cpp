//https://dmoj.ca/problem/dmopc18c1p2
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    bool yes = true;
    vector<int>arr(n+1);

    for(int i = 1;i<=n; i++){
        cin>>arr[i];
    }
    while(true){
        bool sort = true;
        for(int i = 1;i<=n-k;i++){
            if(arr[i]>arr[i+k]){
                sort = false;
                int temp = arr[i];
                arr[i] = arr[i+k];
                arr[i+k] = temp;
            }
        }
        if(sort) break;
    }
    
    for(int i =1; i<n; i++){
        if(arr[i]>arr[i+1]) yes = false;
    }
    
    if(yes) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";


    return 0;
}