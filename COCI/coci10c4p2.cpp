//https://dmoj.ca/problem/ccc11s1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int r, b;
    cin>>r>>b;
    int area = r+b;
    
    for(int i=2;i<=r;i++){
        int w = i;
        int l = (r - (w*2))/2 + 2;

        if(w<1 || l<1)continue;

        if((w*l == area)){
            cout<<max(w,l)<<" "<<min(w,l)<<"\n";
            return 0; 
        }
        
    }
    return 0;
 
}