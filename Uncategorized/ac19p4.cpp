//https://dmoj.ca/problem/ac19p4
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>X(n);
    vector<int>Y(n);
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>X[i]>>Y[i];
    }
    for(int i=0;i<n;i++){
        int curx = X[i];
        int cury = Y[i];
        set<int>Xs; //same Xs, contains y values
        set<int>Ys; //same Ys, contains x values
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(curx==X[j])Xs.insert(Y[j]);
            if(cury==Y[j])Ys.insert(X[j]);
        }
        
        for(int j=0;j<n;j++){
            if(i==j)continue;
            int newx = X[j];
            int newy = Y[j];
            if(Xs.find(newy)!=Xs.end() && Ys.find(newx)!=Ys.end()){
                ans = max(ans, (newy-cury)*(newx-curx));
            }
        }
    }
    cout<<ans<<"\n";


}