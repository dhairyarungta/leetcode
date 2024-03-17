class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    sort(coins.begin(),coins.end());
    int dp [10004][14] = {-1};
    for (int j = 0;j<n;j++)
        dp[0][j] = 0;

    for (int i = 1;i<=amount;i++){

        dp[i][n-1] = i%coins[n-1]==0?i/coins[n-1]:INT_MAX-1;
    }

    for (int i = 1;i<=amount;i++){
        for (int j = n-2;j>=0;j--){
            int left = i - coins[j];
            if(left<0){
                dp[i][j] = dp[i][j+1];
            }
            else{
                    dp[i][j] = min(dp[i-coins[j]][j]+1,dp[i][j+1]);
            }
                
        }
    }
    return dp[amount][0]==INT_MAX-1?-1:dp[amount][0];
    }


};
