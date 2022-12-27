#include <stack>
#include <bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int l = 0,r=0,i=0;
        int n = s.size();
        while(i<n){
            while(s[i]!=' ' && i<n){
                s[r++]=s[i++];            
                }

            if(r>l){
                reverse(s.begin()+l,s.begin()+r);
                if(r>=n)break;

                s[r++]=' ';
                l=r;
            }
            i++;
        }
        while(s[r-1]==' '&&r<=n){
            r--;
        }
        s.resize(r);
        return s;
    }
};
 
string reverseString(string str)
{
    // Write your code here.
    stack<string> st;
    stringstream ss(str);
    
    string temp = "";
    while(ss>>temp){
        st.push(temp);
    }
    temp="";
    while(!st.empty()){
        if(temp.size()!=0){
            char c =32;
            temp.push_back(c);
        }
        temp.append(st.top());
        st.pop();
    }

    return temp;
}



string reverseString(string str)
{
        // Write your code here.
    string ans ="";
    int n = str.size();
    int start = n-1;
    char space = 32;
    while(start>=0){
        if(str[start]==space){
            start--;
        }
        else{
            //means we found the last index character of a word
            //insert space in the ans string now, if only this is not the first word
            if(ans.size()!=0){
                ans.push_back(space);
            }
            string temp ="";
            int j = start;
            while(j>=0 && str[j]!=space){
                j--;
            }
            ans.append(str.substr(j+1,start-j));
            start = j;
        }
    }

    return ans;

}

class Solution {
public:
void addWordtoAns(string str, string &output , int st, int en){
  if (output.size()!=0)
  output.push_back(' ');

  for (int i =st;i<=en;i++){
    output.push_back(str[i]);
  }
}

    string reverseWords(string str) {
          // Write your code here
  char space = 32;
  int n = str.size();
  string output = "";
  int begin = n-1, end = n-1;

  for (;begin>=0;begin--){
        if(begin == n-1 && str[n-1]!=space){
            end = n-1;
        }
        else if(str[begin]!=space && str[begin+1]==space){
            end = begin;
        }
        if(begin==n-1 && str[begin]==space ){
          continue;
        }
        else if(str[begin]==space && str[begin+1]!=space ){
            addWordtoAns(str,output,begin+1,end);
        }

        else if (begin==0 && str[begin]!=space){
          addWordtoAns(str,output,begin,end);
        }
  }

  return output;

    }
};