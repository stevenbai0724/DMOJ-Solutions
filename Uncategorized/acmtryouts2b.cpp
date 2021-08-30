//https://dmoj.ca/problem/acmtryouts2b
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int l, n;
        cin>>l>>n;

        vector<int>arr(l+2);

        for(int i=1;i<=n;i++){
            int c, r, d;
            cin>>c>>r>>d;
            int L = max((int)1, c-r);
            int R = min(l, c+r);

            arr[L] += d;
            arr[R+1] -= d;
        }
        vector<int>psa(l+2);

        for(int i=1;i<=l;i++){
            psa[i] = psa[i-1];
            psa[i] += arr[i];
        }
    
        int b; cin>>b;
        while(b--){
            int x; cin>>x;

            for(int i=1;i<=l;i++){
                x-=psa[i];
                if(x<=0){
                    cout<<i<<"\n";
                    goto nxt;
                }
            }
            cout<<"Bloon leakage\n";
            nxt:;
        }
    }



    return 0;
}