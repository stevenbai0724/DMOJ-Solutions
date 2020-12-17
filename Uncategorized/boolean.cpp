#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int count = 0;
    bool boolean =  false;
    while(true){
        string s; cin>>s;

        if(s=="True"){
            boolean = true;
            break;
        }
        else if(s=="False"){
            boolean = false;
            break;
        }
        count++;
    }
    if(boolean){
        if(count%2==0)cout<<"True";
        else cout<<"False";
    }
    else{
        if(count%2==0)cout<<"False";
        else cout<<"True";
    }

    return 0;
}