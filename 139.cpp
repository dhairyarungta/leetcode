class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(),false);
        for(unsigned int i =0;i<s.size();i++){
            for (int j = 0;j<wordDict.size();j++){
                // if(wordDict[j].size()>s.size()) continue;
                if(i>=wordDict[j].size()-1){
                    if(  (i==(wordDict[j].size())-1 )|| (dp[i-(wordDict[j].size())] )){
                        
                    if(s.substr(i-wordDict[j].size()+1,wordDict[j].size())==wordDict[j]){
                        cout<<"hello";
                        dp[i]= true;
                    }
            
                    }
                }
            }
        }       
        return dp[s.size()-1];
    }
};
