//https://dmoj.ca/problem/dmopc14c6p4
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    double n, m, h; 
    cin>>n>>m>>h;   
    int count = 0;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=n;i>1;i--){
        if(arr[i]-arr[i-1] >h){
            count+=ceil((arr[i]-arr[i-1]-h)/m);
            arr[i-1]+= ceil((arr[i]-arr[i-1]-h)/m) *m;
        }
    }
    cout<<count;


}