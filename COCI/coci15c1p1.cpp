//https://dmoj.ca/problem/coci15c1p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    //P, K, H, T
    string s; cin>>s;
    gp_hash_table<char, int>mp;
    
    mp['P'] = 1;
    mp['K'] = 2;
    mp['H'] = 3;
    mp['T'] = 4;

    vector<int>ans{0,13,13,13,13};

    vector<vector<bool>>arr(5, vector<bool>(14));

    int n = s.length();

    for(int i=0;i<=n-3;i+=3){
        string temp = s.substr(i,3);

        if(arr[mp[temp[0]]][stoi(temp.substr(1,2))]){
            cout<<"GRESKA"<<"\n";
            return 0;
        }
        arr[mp[temp[0]]][stoi(temp.substr(1,2))] = true;

        ans[mp[temp[0]]]--;

    }
    for(int i=1;i<=4;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";



    return 0;
}