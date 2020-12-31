//https://dmoj.ca/problem/dmopc19c4p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string qwerty; 
    std::getline(cin, qwerty);
    int t = stoi(qwerty);
    for(t;t>0;t--){
        string s; 
        std::getline(std::cin, s);
        vector<int>arr;//(
        vector<int>arr2;//)

        for(int i=0;i<s.length();i++){
            if(s[i]=='(')arr.push_back(i);
            if (s[i]==')')arr2.push_back(i);
        }

        if(arr.size()!=arr2.size()){
            cout<<"NO\n";
            continue;
        }
        bool found = true;
        for(int i=0;i<arr2.size();i++){
            if(arr[i]>arr2[i])found = false;
        }
        if(found)cout<<"YES\n";
        else cout<<"NO\n";

    }

    return 0;
}