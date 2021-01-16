//https://dmoj.ca/problem/mockccc15j2
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    double p, q, w;//mark, goal, percent of exam
    cin>>p>>q>>w;
    w *= 0.01;
    q -=0.5;

    double ans =  round((q-(p*(1-w)))/w);       
    
    if(ans<=100 && ans>0)cout<<ans;
    else if(ans<=0) cout<<0;
    else cout<<"DROP THE COURSE";

    return 0;
}