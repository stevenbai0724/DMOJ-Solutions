#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string>names(n);
    vector<int>score(n);

    for(int i = 0; i<n; i++){
        cin>>names[i];
        cin>>score[i];
    }

    for(int i = 0; i<n; i++){
        if(score[i]>m){
            cout<<names[i]<<" will advance"<<"\n";
        }
        else cout<<names[i]<<" will not advance"<<"\n";

    }
    return 0 ;
}