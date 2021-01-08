//https://dmoj.ca/problem/coci08c3p1
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr(6);
    int a = 0;
    int p = 0;

    for(int i =1;i<=5;i++){
        int sum = 0;
        for(int j=1;j<=4;j++){
            int x;
            cin>>x;
            sum+=x;
        }
        arr[i] = sum;
    }
    for(int i=1;i<=5;i++){
        if(arr[i]>p){
            p = arr[i];
            a = i;
        }
    }
    cout<<a<<" "<<p;

    return 0;
}