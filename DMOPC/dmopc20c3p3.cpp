//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int md = 1e9 + 7;
int pw(int b, int e){
    int num = 1;
    for(int i=1;i<=e;i++){
        num*=b;
    }
    return num;
}
bool fill(vector<int>a, int c){

    for(int i=1;i<a.size();i++){
        if(a[i]!=c)return false;
    }
    return true;
}
bool over(vector<int>a, int c){
    for(int i=1;i<a.size();i++){
        if(a[i]>c)return true;
    }
    return false;
}   
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int q; cin>>q;
    while(q--){
        int n, m, k,b;
        cin>>n>>m>>k>>b;

        vector<int>arr(n+1);
        vector<int>cnt(n+1);
        int cur = 1;
        bool good = false;
        while(true){
            if(fill(arr, m)){
                good = true;
                break;
            }
            if(over(arr, m)){
                break;
            }

            int lo = cur-1;
            if(lo<1)lo = n;
            int hi = cur+1;
            if(hi>n)hi = 1;

            arr[lo]++;
            arr[hi]++;
            arr[cur]+=k;
            cnt[cur]++;
            cur++;
            if(cur>n)cur = 1;
            
        }
        int ans = 0;
        if(!good)cout<<-1<<"\n";
        else{
            for(int i =0;i<n;i++){
                int p = pw(b,i);
                ans+= p*cnt[i+1];
            }
            cout<<ans%md<<"\n";
        }


    }
    
}