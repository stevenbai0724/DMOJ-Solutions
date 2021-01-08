//https://dmoj.ca/problem/coci14c5p1
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr(18);
    int ans = 0;

    for(int i = 1; i<=8; i++){
        cin>> arr[i];
    }
    arr[9] = arr[1];
    arr[10] = arr[2];
    arr[11] = arr[3];
    arr[12] = arr[4];

    for(int i = 1; i<=8; i++){
        int sum = 0;
        for(int j = 0; j<4; j++){
            sum += arr[i+j];
        }
        ans = max(ans, sum);
    }
    cout<<ans;


    return 0;
}