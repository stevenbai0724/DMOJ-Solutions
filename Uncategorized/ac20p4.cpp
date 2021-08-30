//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<pair<int, int>>arr(m+1);

    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        arr[i] = {a,b};
    }
    vector<int>ans{(int)1e18,(int)1e18};


    for(int i=1;i<m;i++){
        int a = arr[i].first;
        int b = arr[i].second;
        
        vector<int>aArr;
        vector<int>bArr;
        vector<int>temp{a,b};
        

        for(int j=i+1;j<=m;j++){
            
            int x = arr[j].first;
            int y = arr[j].second;
            if((a==x && b==y) || (a==y && b==x))continue;
        
            if(x == a)aArr.push_back(y);
            else if(y == a)aArr.push_back(x);

            if(x == b)bArr.push_back(y);
            else if(y == b)bArr.push_back(x);
            

        }
        if(aArr.empty() || bArr.empty())continue;
        sort(bArr.begin(), bArr.end());
        for(int num : aArr){
            if(*lower_bound(bArr.begin(), bArr.end(), num)==num){
                temp.push_back(num);
                sort(temp.begin(), temp.end());
                if(!std::lexicographical_compare(ans.begin(),ans.end(),temp.begin(),temp.end()))ans = temp;

                auto it = find(temp.begin(), temp.end(), num);
                temp.erase(it);
                
            }
        }
    }

    vector<int>killyourself{(int)1e18,(int)1e18};
    if(ans!= killyourself){
        cout<<3<<"\n";
        for(auto x: ans)cout<<x<<" ";
        cout<<"\n";

        return 0;
    }
    for(int i=1;i<m;i++){   
        int a = arr[i].first;
        int b = arr[i].second;
 
        vector<int>temp{a,b};
        for(int j=i+1;j<=m;j++){
            int x = arr[j].first;
            int y = arr[j].second;
            if((a==x && b==y) || (a==y && b==x))continue;
         

            set<int>s;

            s.insert(a); s.insert(b); s.insert(x); s.insert(y);
            if(s.size()==4){
                temp.push_back(x);
                temp.push_back(y);

                sort(temp.begin(), temp.end());
                if(temp<ans)ans = temp;
                auto it = find(temp.begin(), temp.end(), x);
                temp.erase(it);
                it = find(temp.begin(), temp.end(), y);
                temp.erase(it);

            }
        }
    }
    if(ans!= killyourself){
        cout<<4<<"\n";
        for(auto x: ans)cout<<x<<" ";
        cout<<"\n";
        return 0;
    }
    cout<<-1<<"\n";
    
    
    
    return 0;
}