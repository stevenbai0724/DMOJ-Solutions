//https://dmoj.ca/problem/coci07c5p1
#include <bits/stdc++.h>
using namespace std;
#define int long long

double op(double a, double b, int o){
    switch (o){
        case 0:
        return a+b;
        
        case 1:
        return a-b;

        case 2:
        return a*b;

        case 3:
        return a/b;
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<char>arr{'+','-','*','/'};
    int a,b,c;
    cin>>a>>b>>c;
    string ans = "";

    for(int i=0;i<4;i++){
        if(a==op(b,c,i)){
            ans+= to_string(a)+"="+to_string(b)+arr[i]+to_string(c);
            cout<<ans<<"\n";
            return 0;
        }
    }
    for(int i=0;i<4;i++){
        if(c==op(a,b,i)){
            ans+= to_string(a)+arr[i]+to_string(b)+"="+to_string(c);
            cout<<ans<<"\n";
            return 0;
        }
    }
    
    return 0;

}