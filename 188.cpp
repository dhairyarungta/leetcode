class Solution {
public:
    int maxProfit(int l, vector<int>& prices) {
        int numTransactions = 0;
        int ** dp = new int*[l+1];
        for (int i =0 ;i<l+1;i++)
            dp[i] = new int[prices.size()];
        
        for (int i =0 ;i<l+1;i++)
            for (int j = 0;j<prices.size();j++)
                dp[i][j] =0;

        
        for (int k =1;k<l+1;k++)
        {   
            int minval = prices[0];
            for (int i =1;i<prices.size();i++)
            {
                minval = min(minval,prices[i]-dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i]-minval);
            }
        }
        return dp[l][prices.size()-1];

    }
};