//https://dmoj.ca/problem/dmopc14c1p4
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int add = abs(c-a) + abs(d-b);
    int temp = 0;
    
    string s; cin>>s;
    int ss = stoi(s.substr(17,2));
    int mi = stoi(s.substr(14,2));
    int hh = stoi(s.substr(11,2));
    int dd = stoi(s.substr(8,2));
    int mm = stoi(s.substr(5,2));
    int yy = stoi(s.substr(0,4));
    ss += add;
    temp = ss/60;
    ss%=60; 
    mi+=temp;
    temp = mi/60;
    mi%=60;
    hh+=temp;
    temp = hh/24;
    hh%=24;
    dd+=temp;

    while(true){
        if(((mm%2==1 && (mm<=7)) || (mm%2==0 && mm>=8)) && dd>=32 && mm!=2){
            dd-=31;
            mm++;
            if(mm==13){
                mm=1;
                yy++;
                continue;
            }
            continue;
        }
        if(((mm%2==0 && (mm<=7)) || (mm%2==1 && mm>=8)) && dd>=31 && mm!=2){
            dd-=30;
            mm++;
            continue;
        }
        if(mm==2){
            if(yy%4==0 && dd>=30){
                dd-=29;
                mm++;
                continue;
            }
            else if(yy%4!=0 && dd>=29){
                dd-=28;
                mm++;
                continue;
            }
        }
        break;
    }
    string ans = to_string(yy) + ":";
    
    if(mm/10==0)ans+= '0'+ to_string(mm) + ':';
    else ans+= to_string(mm) + ':';

    if(dd/10==0)ans+= '0'+ to_string(dd) + ':';
    else ans+= to_string(dd) + ':';
    
    if(hh/10==0)ans+= '0'+ to_string(hh) + ':';
    else ans+= to_string(hh) + ':';

    if(mi/10==0)ans+= '0'+ to_string(mi) + ':';
    else ans+= to_string(mi) + ':';

    if(ss/10==0)ans+= '0'+ to_string(ss);
    else ans+= to_string(ss);
    

    cout<<ans;
    return 0;
}
