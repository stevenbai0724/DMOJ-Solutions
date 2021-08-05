//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        vector<int>arr(n);
        vector<int>good;
        vector<int>bad;
        set<int>s;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }
        if(s.size()==1 && !(n&1)){
            cout<<-1<<"\n";
            continue;
        }
        sort(arr.begin(), arr.end());
        good = arr;
        auto temp = good;
        reverse(temp.begin(), temp.end());
        bad = temp;
        if(n&1){
            for(int i=0;i<n;i++){
                cout<<arr[i];
                if(i<n-1)cout<<" ";
            }
            cout<<"\n";
            continue;
        }
        else{
            for(int i=0;i<n;i++){
                if(i%2==0){
                    cout<<good.back();
                    good.pop_back();
                }
                else {
                    cout<<bad.back();
                    bad.pop_back();
                }
                if(i<n-1)cout<<" ";
            }
            cout<<"\n";
        }
    
        

    }

    return 0;
}