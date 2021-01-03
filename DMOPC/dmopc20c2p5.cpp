//https://dmoj.ca/problem/dmopc20c2p5
/*
N^2 solution, 50/100 points
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    int count = 0;
    for(int i=1;i<=n;i++){
        int mx = 0;
        vector<int>freq(n+1);
        for(int j=i;j<=n;j++){
            freq[arr[j]]++;
            mx = max(mx, freq[arr[j]]);
            if(mx>(j-i+1)/2){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}
