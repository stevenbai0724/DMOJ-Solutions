//https://dmoj.ca/problem/wac5p2
#include <bits/stdc++.h>
using namespace std;
vector<int>arr(1);
vector<int>sufMax(1);
vector<int>sufMin(1);
int n,q,l,e;
bool good(int x){
    return abs(l-sufMax[x])<=e && abs(l-sufMin[x])<=e;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>q;
    arr.resize(n+1);
    sufMax.resize(n+1);
    sufMin.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sufMax[n] = arr[n];
    sufMin[n] = arr[n];
    for(int i=n-1; i>0;i--){
        sufMax[i] = max(arr[i], sufMax[i+1]);
        sufMin[i] = min(arr[i], sufMin[i+1]);
    }

    for(;q>0;q--){
        cin>>l>>e;
        int lo = 0;
        int hi = n;
        bool found = true;
        while(lo+1<hi){
            int mid = (lo+hi)/2;

            if(good(mid)) hi = mid;
            else lo = mid;

            if((lo+1 == hi) && !good(hi)){
                cout<<0<<"\n";
                found = false;
            }
        }
        if(found)cout<<n-hi+1<<"\n";
    }
    return 0;
}