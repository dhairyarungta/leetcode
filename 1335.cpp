class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size(); 
        if(d>n)
            return -1;

        int dp[400][400];
        for (int i = 0;i<n;i++)
            for(int j = 0;j<d+1;j++)
                dp[i][j] = INT_MAX;

        int curMax = 0;
        for (int i = n-1;i>=d-1;i--){
            dp[i][d] = max(curMax, jobDifficulty[i]);
            curMax = dp[i][d];
        }
    
        for (int j = d-1;j>=1;j--){
            for(int i = j-1  ;i<n-(d-j);i++)
            {
                int hardest = 0;
                for (int k = i; k<n-(d-j);k++){
                   hardest = max(hardest,jobDifficulty[k]);
                   dp[i][j] = min(hardest+dp[k+1][j+1],dp[i][j]);
                      
                }
            }
        }
        return dp[0][1];
    }
};
