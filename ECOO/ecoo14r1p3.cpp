//https://dmoj.ca/problem/ecoo14r1p3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 5;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>>arr(n+1, vector<char>(m+1));
        vector<vector<bool>>vis(n+1, vector<bool>(m+1));

        for(int i=1;i<=n;i++){
            string s; cin>>s;

            for(int j=1;j<=m;j++){
                arr[i][j] = s[j-1];
            }

        }
        

        int w; cin>>w;
        queue<string>q;
        string qwe;
        getline(cin, qwe);
        for(int i=1;i<=w;i++){
            string temp;
            getline(cin, temp);
            string psh = "";

            for(char ch: temp){
                if(65 <= (int)ch && (int)ch <=90)psh += ch;
            }

            q.push(psh);

        }
      
        while(!q.empty()){
            string cur = q.front();
            int len = cur.length();
            q.pop();

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(arr[i][j]==cur[0]){

                        if(i>=len){
                            string temp = "";
                            for(int k=i;k>=i-len+1;k--){
                                temp+=arr[k][j];
                            }
                            if(temp==cur){
                                for(int k=i;k>=i-len+1;k--){
                                    vis[k][j] = true;
                                }
                            }
                        }

                        if(i>=len && j+len-1<=m){
                            string temp = "";
                            int x = i;
                            int y = j;
                            for(int k=1;k<=len;k++, x--, y++){
                                temp += arr[x][y];
                            }
                            if(temp==cur){
                                x = i;
                                y = j;
                                for(int k=1;k<=len;k++, x--, y++){
                                    vis[x][y] = true;
                                }
                            }
                        }

                        if(j+len-1<=m){
                            string temp = "";
                            for(int k=j;k<=j+len-1;k++){
                                temp += arr[i][k];
                            }
                            if(temp==cur){
                                for(int k=j;k<=j+len-1;k++){
                                    vis[i][k] = true;
                                }                           
                            }
                        }

                        if(i+len-1<=n && j+len-1<=m){
                            string temp = "";
                            int x = i;
                            int y = j;
                            for(int k=1;k<=len;k++, x++, y++){
                                temp += arr[x][y];
                            }
                            if(temp==cur){
                                x = i;
                                y = j;
                                for(int k=1;k<=len;k++, x++, y++){
                                    vis[x][y] = true;
                                }     
                            }
                        }

                        if(i+len-1<=n){
                            string temp = "";
                            for(int k=i;k<=i+len-1;k++){
                                temp+=arr[k][j];
                            }
                            if(temp==cur){
                                for(int k=i;k<=i+len-1;k++){
                                    vis[k][j] = true;
                                }
                            }
                        }

                        if(i+len-1<=n && j>=len){
                            string temp = "";
                            int x = i;
                            int y = j;
                            for(int k=1;k<=len;k++, x++, y--){
                                temp += arr[x][y];
                            }
                            if(temp==cur){
                                x = i;
                                y = j;
                                for(int k=1;k<=len;k++, x++, y--){
                                    vis[x][y] = true;
                                }     
                            }      
                        }

                        if(j>=len){
                            string temp = "";
                            for(int k=j;k>=j-len+1;k--){
                                temp += arr[i][k];
                            }
                            if(cur == temp){
                                for(int k=j;k>=j-len+1;k--){
                                    vis[i][k] = true;
                                }                   
                            }
                        }

                        if(j>=len && i>=len){
                            string temp = "";
                            int x = i;
                            int y = j;
                            for(int k=1;k<=len;k++, x--, y--){
                                temp += arr[x][y];
                            }
                            if(temp==cur){
                                x = i;
                                y = j;
                                for(int k=1;k<=len;k++, x--, y--){
                                    vis[x][y] = true;
                                }     
                            }                    
                        }
                    }
                }
            }


        }
        string ans = "";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!vis[i][j])ans += arr[i][j];
            }
        }
        cout<<ans<<"\n";

    }



    return 0;
}