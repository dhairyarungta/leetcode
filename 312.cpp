class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int vec[nums.size()+2];
        int n = 1;
        for(int x :nums)
        {
            if(x>0)
                vec[n++]=x;
        }
        vec[0]=vec[n++]=1;

        int dp[n][n];
        for(int i =0 ;i<n;i++)
            for (int j =0 ;j<n;j++)
                dp[i][j]=0;

        for (int k =2; k<n;++k)
        {
            for (int left =0;left<n-k;++left )
            {
                int right = left+k;
                for (int i = left+1;i<right;++i)
                {   
                    int temp = vec[left]*vec[i]*vec[right]+dp[left][i]+dp[i][right];
                    dp[left][right] = max(dp[left][right], temp);
                }
            }
        }
        return dp[0][n-1];
    }
};