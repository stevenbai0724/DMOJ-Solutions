//https://dmoj.ca/problem/dmopc15c1p3
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s, t;
    cin>>s>>t;

    for(int i=0;i<=25;i++){
        string temp = "";

        for(int j=0;j<s.length();j++){
            int n = (int)s[j];
            if(n-i<97) n = 122-(97-(n-i)) +1;
            else n-=i;

            temp+= (char)n;
        }
        
        for(int j=0;j<s.length()-t.length()+1;j++){
            if(temp.substr(j, t.length()) == t){
                cout<<i<<"\n"<<temp;
                return 0;
            }
        }

    }
    return 0;
}