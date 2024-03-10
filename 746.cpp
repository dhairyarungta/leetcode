class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==1)
            return cost[0];

        vector<int>dp(cost.size());
        int n = cost.size();
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];

       for(int i = n-3;i>=0;i--) 
        {
            dp[i] = cost[i]+min(dp[i+1],dp[i+2]);           
        }
        return min(dp[0],dp[1]);
    }
};
