#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    
    int n, m;
    cin>>n>>m;
    string s = "";
    int count = 0;
    for(int i =1; i<=n; i++){
        string t; cin>>t;
        s = s + t+" ";
    }

    for(int i =1; i<=m; i++){
        int x; cin>>x;

        bool yes = true;
        for(int j =0; j<x;j++){
            string str; cin>>str;
            size_t f = s.find(str);
            if(f>=0 && f<s.length()) continue;
            else yes = false;
        }
        if(yes) count++;
        
    }
    cout<<count;


    return 0;
}