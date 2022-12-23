//Time Complexity probably close to O(n^2)

#include <bits/stdc++.h>

void addWordtoAns(string str, string &output , int st, int en){
  if (output.size()!=0)
  output.push_back(' ');

  for (int i =st;i<=en;i++){
    output.push_back(str[i]);
  }
}
string reverseString(string str) {
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