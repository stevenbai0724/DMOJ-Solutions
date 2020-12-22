#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >>n>>m;
    vector<int>arr;
    vector<int>psa;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        arr.push_back(x);
    }
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr.at(i);
        psa.push_back(sum);
    }
    for(int i = 0;i<m; i++){
        int x; cin>>x;
        int s = 0;
        
        
        if( psa.at(x-1)< (psa.at(psa.size()-1))-psa.at(x-1)) {
            s = psa.at(psa.size()-1) - psa.at(x-1);
            psa.erase(psa.begin()+x, psa.end());
            arr.erase(arr.begin()+x, arr.end());
            cout<<s<<"\n";
         
        }else{
            s = psa.at(x-1);
            psa.erase(psa.begin(), psa.begin()+x);
            arr.erase(arr.begin(), arr.begin()+x);
            int sm = 0;
            for(int j = 0; j<arr.size(); j++){
                sm+= arr.at(j);
                psa.at(j) = sm;
            }
            cout<<s<<"\n";
         
        }   
    }
    return 0 ;
}

