//https://dmoj.ca/problem/vmss7wc16c2p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int m = n;
    n*=5;
    vector<vector<char>>arr(n+1, vector<char>(n+1));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] = '.';
        }
    }
    queue<pair<int, int>>q;
    q.push({1,1});
    q.push({1,2});
    q.push({1,3});
    q.push({1,4});
    q.push({1,5});
    q.push({2,1});
    q.push({3,1});
    q.push({4,1});
    q.push({5,1});
    q.push({5,2});
    q.push({5,3});
    q.push({5,4});
    q.push({5,5});
    q.push({4,5});
    q.push({3,5});
    q.push({3,4});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int newx = x*m - (m-1);
        int newy = y*m - (m-1);
        for(int i=newx;i<newx+m;i++){
            for(int j=newy;j<newy+m;j++){
                arr[i][j] = 'G';
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }


    return 0;
 
}