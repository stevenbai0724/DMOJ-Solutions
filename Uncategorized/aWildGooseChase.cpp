//https://dmoj.ca/problem/awildgoosechase
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, t;
    cin>>n>>t;
    vector<int>psa(1e5 + 7);
    vector<int>arr(1e5 + 7);
    int last = 1e5 + 6;
    vector<int>ans;
    for(int i =1;i<=n;i++){
        int x, acc;
        cin>>x>>acc; //acc is the accused

        if(acc==-1){
            psa[0]++;
            psa[x]--;
            psa[x+1]++;
            psa[last]--;
        }
        else{
            psa[acc]++;
            psa[acc+1]--;
        }
    }
    int sum = 0;
    for(int i =0;i<=last;i++){
        sum+=psa[i];
        arr[i] = sum;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==t) ans.push_back(i);
    }
    if(ans.size()==0){
        cout<<-1;
        return 0;
    }
    for(int i =0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }


    return 0;
}