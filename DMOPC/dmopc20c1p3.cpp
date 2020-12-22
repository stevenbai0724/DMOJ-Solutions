#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    int mx = 0;
    int mx2 = 0;   
    int index = 0;
    int count= 0;
    for(int i =1; i<=n; i++){//input, finding largest
        cin>>arr[i];
        if(arr[i]>mx){
            mx = max(mx, arr[i]);
            index = i;
        }
    }
    int index2 = 0;
    for(int i = index; i<=n; i++){
        if(arr[i]>arr[i-1]) index2 = i;       
    }
    for(int i = index2; i<=n; i++){
        mx2 = max(mx2, arr[i]);
    }
    bool dsc = true;
    bool inc = true;
    for(int i =1; i<=n; i++){
        if(arr[i]<arr[i+1]) dsc = false;
    }
    for(int i =1; i<=n; i++){
        if(arr[i]>arr[i+1]) inc = false;
    }
    if(dsc||inc) cout<<0;
    else{
        for(int i =index+1; i<=n; i++){
            if(arr[i]<mx2) count += abs(arr[i]-mx2);
        }
        cout<<count;
    }





    return 0 ;
}