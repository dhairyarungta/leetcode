class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int overallMaxProfit = 0;
        int minVal =prices[0];
        for(int i =1;i<prices.size();i++){
            overallMaxProfit = max(overallMaxProfit,prices[i]-minVal);
            if(minVal>prices[i]){
                minVal= prices[i];
            }
        }
        return overallMaxProfit;

    }
};