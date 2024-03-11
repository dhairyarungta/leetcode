#include <map>
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        for(auto i : nums)
        {
            mp[i]++;
        }
        vector<int>vec(10001,0);
        for(auto [i,j]:mp)
        {
            vec[i]=i*j;
        }
        if (vec.size()==1)
            return vec[0];

        vector<int>dp(vec.size());
        dp[0] = vec[0];
        dp[1] = max(vec[0],vec[1]);
        for (int i = 2;i<vec.size();i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+vec[i]);
        }
        return dp[vec.size()-1];
    }
};
