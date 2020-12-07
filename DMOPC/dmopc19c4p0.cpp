//https://dmoj.ca/problem/dmopc19c4p0
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string a, b;
    cin>>a>>b;
    int count = 0;

    for(int i = 0; i<a.size(); i++){
        if(a[i]!=b[i]){
            count++;
        }
    }
    if(count==1 ) cout<<"LARRY IS SAVED!";
    else cout<<"LARRY IS DEAD!";


    return 0 ;
}