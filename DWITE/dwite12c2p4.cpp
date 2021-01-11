//https://dmoj.ca/problem/dwite12c2p4
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    for(int t=5;t>=1;t--){
        int n; cin>>n;
        bool stop = false;
        vector<int>nums(n), arr(n), ans;
        for(int i=0;i<n;i++){
            nums[i] = i+1;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            if(nums.size()<=arr[i]){
                cout<<"IMPOSSIBLE"<<endl;
            
                stop = true;
                break;
            }
            vector<int>::iterator ptr = nums.end()-arr[i]-1;
            ans.push_back(*ptr);
            nums.erase(ptr);
        }
        if(stop)continue;
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}