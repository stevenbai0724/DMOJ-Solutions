//https://dmoj.ca/problem/bfs17p2
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    
        vector<int>arr(7);

        int n; cin>>n;
        int mx = 0;
        int mx2 =0;
        for(int i =0;i<n;i++){
            string s; cin>>s;
            if(s=="red")arr[1]++;
            else if(s=="orange")arr[2]++;
            else if(s=="yellow")arr[3]++;
            else if(s=="green")arr[4]++;
            else if(s=="blue")arr[5]++;
            else if(s=="black")arr[6]++;
        }
        for(int i =1;i<=6;i++){
            mx = max(mx, arr[i]);
        }
        mx2 = n-mx;
        cout<<min(mx, mx2+1) + mx2;
    return 0;

}