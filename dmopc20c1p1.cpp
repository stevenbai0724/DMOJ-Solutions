#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    for(int i =0; i<n; i++){
        string s; cin>>s;
        int count = 0;
        for(int j=0; j<s.length(); j++){
            if(s[j]=='C' || s[j]=='M') count++;
        }
        if(count==0) cout<<"PASS"<<"\n";
        if(count==1) cout<<"FAIL"<<"\n";
        if(count>=2) cout<<"NEGATIVE MARKS"<<"\n";
    }


    return 0 ;
}