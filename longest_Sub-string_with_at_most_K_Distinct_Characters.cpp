#include<bits/stdc++.h>

//O(n) The one below is the cleaner version of the second code, same logic
int getLengthofLongestSubstring(int k, string s)
{
   // Write your code here.
   int n = s.size();
   int types=0;
   map<char, int> mp;
   int overallMax = INT_MIN;
   int j = 0;
   for (int i =0;i<n;i++){
     mp[s[i]]++;

     if (mp[s[i]] == 1) {
         types++;
         while(types>k){
            mp[s[j]]--;
            if(mp[s[j]]==0)
               types--;
            j++;
         }
      }
     overallMax= max(overallMax,i-j+1);
   }
   return overallMax;
}


int getLengthofLongestSubstring(int k, string s)
{  map<char, int> mp;
   int n = s.size();
   int types = 0;
   int maxLen = INT_MIN;
   int curLen = 0;
   int j =0;
   for (int i=0;i<n;i++){
      if(mp[s[i]]!=0){
        mp[s[i]]++;
        maxLen = max(maxLen, i-j +1);
      }
      else if(mp[s[i]]==0 && types<k){
         mp[s[i]]++; types++;
         maxLen = max(maxLen, i-j+1 );
      }
      else {
        while (types > k-1) {
          mp[s[j]]--;
          if (mp[s[j]] == 0)
            types--;
          j++;
         }
         mp[s[i]]++;
         types++;
      }
   }
   return maxLen;
}
