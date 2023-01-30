class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        if(prices.size()==1)
            return prices.size();

        long long ans = 1,start = 0, end = 1;
        bool check = true;

        for (;end<prices.size();end++){
                if(prices[end]-prices[end-1]!=-1){
                    start=end;
                }
                ans+=(end-start+1);
        }

        return ans;
    }
};