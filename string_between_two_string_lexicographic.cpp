#include <bits/stdc++.h>
using namespace std;

string findNextFunction(string s){
    int n = s.size();
    int i;
    for( i =n-1;i>=0;i--){
        if(s[i]!='z'){
            s[i]++;
            break;
        }
    }

    if(i==-1){
        return "-1";
    }
    else return s;


}


int main(){
    string s,t;
    //assuming s , t have the same length
    cin>>s>>t;
    string ans = findNextFunction(s);
    if(ans!=t && ans <t){
        cout<<ans;

    }

    else cout<<"-1";
    
}