//https://dmoj.ca/problem/utso21p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
vector<int>tri(102);

vector<int> sumOfTri(int n){
    vector<int>arr;
    while(n>0){
        for(int i=1;i<=101;i++){
            if(tri[i]>n){
                n-=tri[i-1];
                arr.push_back(i-1);
                break;
            }
        }
    }
    return arr;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    for(int i=1;i<=101;i++){
        tri[i] = (i)*(i+1)/2;
    }
    vector<int>ans(101);
    for(int i=1;i<=100;i++){
        ans[i] = 1;
    }
    int k; cin>>k;
    auto it = find(tri.begin(), tri.end(), k);

    if(k==0){
        cout<<1<<"\n"<<2<<"\n";
        return 0;
    }
    if(k==1){
        cout<<1<<"\n"<<1<<"\n";
        return 0;
    }
    if(it!=tri.end()){
        int ind = it-tri.begin();
        cout<<ind<<"\n";
        for(int i=1;i<=ind;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    it = upper_bound(tri.begin(), tri.end(), k);
    int len = it-tri.begin();
    vector<int>spaces = sumOfTri(*it-k);

    int cur = 1;
    for(auto s: spaces){
        for(int i=cur;i<(cur+s);i++){
            ans[i] = 2;
        }
        cur+=1+s;
    }
    cout<<len<<"\n";
    for(int i=1;i<=len;i++){
        cout<<ans[i]<<" ";
    }
    

    return 0;
}