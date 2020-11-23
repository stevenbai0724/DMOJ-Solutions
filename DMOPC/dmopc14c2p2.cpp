//https://dmoj.ca/problem/dmopc14c2p2
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    cin.tie(nullptr)->sync_with_stdio(false);

    int l;
    string s;
    cin >> l >>s;

    int count =0;
    int ans = 0;
    vector<string>logs;

    for(int i =0; i<l; i++){
        
        if(s[i]=='X' ){
            string log = "";
            for(int j =0; j<count; j++){
                log += "O";
            }
            logs.push_back(log);
            count = 0;
        }
        if(s[i]=='O') count++;
        if(i == l-1){
            string last = "";
            for(int j =0; j<count; j++){
                last += "O";
            }
            logs.push_back(last);
        }
    }
    
    for(int i = 0; i<logs.size(); i++){
        if(logs.at(i) !="") ans++;
      
    }
    cout<<ans<<"\n";
    for(int i = 0; i<logs.size(); i++){
        if(logs.at(i)!="")cout<<logs.at(i)<<"\n";
    }   

    return 0;
}