//https://dmoj.ca/problem/ecoo16r1p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int times = 10;

    while(times--){
        int n; cin>>n;

        vector<int>arr(n+1);
        vector<int>ind(n+1);

        vector<bool>skip(n+1, false);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            ind[arr[i]] = i;
            
        }

        int cur = n;

        for(int i=n;i>=1;i--){
            if(arr[i]==cur){
                skip[arr[i]] = true;
                cur--;
            }
        }
        int cost = 0;
        for(int i=n;i>=1;i--){
            if(skip[i])continue;
            int index = ind[i];
            cost+=(index-1);

            for(int j=index;j>1;j--){
                arr[j] = arr[j-1];
                ind[arr[j-1]]++;
            }

            arr[1] = i;

        }

        cout<<cost<<"\n";
        


    }



    return 0;
}