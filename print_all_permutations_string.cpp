#include <bits/stdc++.h>
using namespace std;

void permute(string s , string ans){
    if(s.size()==0){
        cout<<ans<<"\n";
        return;
    }
    set<char> check ;
    for (int i =0;i<s.size();i++){
        char c = s[i];
        if(check.count(c)){
            continue;
        }
        check.insert(c);
        string leftstr = s.substr(0,i);
        string rightstr= s.substr(i+1);
        permute(leftstr+rightstr, ans+c);
    }
}

int main(){
    string s;
    cin>> s;
    string ans ="";
    permute(s,ans);
}