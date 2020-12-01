//https://dmoj.ca/problem/dmopc14c3p3
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<string>names(n+1);
    vector<int>skill(n+1);

    for(int i =1;i<=n;i++){
        cin>>names[i]>>skill[i];
    }
    int q; cin>>q;
    for(q;q>0;q--){
        int s, d;
        cin>>s>>d;
        int min = 1e9;
        int index = 0;
        bool found = false;

        for(int i =1;i<=n;i++){
            if(skill[i]<=(s+d) && skill[i]>=s){
                if(skill[i]<min){
                    min = skill[i];
                    index = i;
                    found = true;
                }
            }
        }
        if(found)cout<<names[index]<<"\n";
        else cout<<"No suitable teacher!"<<"\n";


    }
    return 0;
}