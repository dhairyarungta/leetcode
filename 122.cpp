class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;

        long long profit =0 ;
        
        for (int i = 1;i<prices.size();i++)
        {
            if(prices[i]-prices[i-1]>0)
                profit+=prices[i]-prices[i-1];
            

        }
        return profit;
    }
};