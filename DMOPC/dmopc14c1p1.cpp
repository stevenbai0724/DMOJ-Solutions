#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    vector<int>array(n+1);

    for(int i = 1; i<=n; i++){
        int x; cin>>x;
        array[i] = x;
    }
    sort(array.begin(), array.end());
    
    if(n%2 == 1){
        cout<< array[n/2 + 1];
    }
    else{
        double l = array[n/2];
        double h = array[n/2 + 1];
        int ans = round((l+h)/2);
        cout << ans<<"\n";
    }


    return 0;
}