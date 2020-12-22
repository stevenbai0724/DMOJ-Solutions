#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    
    int n; cin>>n;
    string s; cin>>s;

    vector<vector<char>>arr(10000, vector<char>(n+2, '.'));
    vector<bool>emp(10000, false); //checking to see if each row is empty or not
    int curx = 5000;
    int cury = 1;
    for(int i=0;i<s.length();i++){
        
        if(s[i]=='v'){
            curx++;
            emp[curx] = true;
            arr[curx][cury] = (char)92;
            cury++; 
        }
        else if(s[i]=='^'){
            emp[curx] = true;
            arr[curx][cury] = '/';
            curx--;
            cury++;   
        }
        else if(s[i]=='>'){
            emp[curx] = true;
            arr[curx][cury] = '_';
            cury++;    
        }
    }
    for(int i=1;i<=9999;i++){
        if(!emp[i]) continue;
        for(int j=1;j<=n;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
