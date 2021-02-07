//https://dmoj.ca/problem/dmopc17c4p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    vector<int>first(n+1);
    vector<int>freq(n+1);
    vector<int>ans(n+1);   
    vector<int>s;
    set<int>nums;

    for(int i=1;i<=n;i++){
        nums.insert(i);
        cin>>arr[i];
        if(!freq[arr[i]]){
            first[arr[i]] = i;
            s.push_back(arr[i]);
        }
        freq[arr[i]]++;
    }
    sort(s.begin(), s.end());
    if(s.size()==1){
        cout<<-1<<"\n";
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(i==s.size()-1){
            ans[first[s[0]]] = s[i];
        }
        else{
            ans[first[s[i+1]]] = s[i];
        }
        nums.erase(nums.find(s[i]));
    }
    queue<int>q;
    for(auto x: nums){
        q.push(x);
    }
    for(int i=1;i<=n;i++){
        if(!ans[i]){
            ans[i] = q.front();
            q.pop();
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }




    return 0;
}