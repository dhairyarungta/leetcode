class Solution {
    string gl_string;
public:
    bool recursiveHelper(vector<string>&wordDict,unsigned int idx,vector<int>&dp){
        if(dp[idx]!=-1)
            return dp[idx]==1;

        for (auto word:wordDict){
            if(idx>=word.size()-1) {
                if(idx==word.size()-1 || recursiveHelper(wordDict, idx-word.size(),dp)==true){
                    if(gl_string.substr(idx-word.size()+1,word.size())==word){
                    dp[idx]=1;
                    return true;
                    }
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        gl_string =s;
        vector<int>dp(s.size(),-1);
         bool ans = recursiveHelper(wordDict, s.size()-1,dp);
        return ans; 
    }
};
