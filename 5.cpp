class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        bool dp[1005][1005];
        
        for (int i =0 ;i<size;i++)
            for (int j =0;j<size;j++)
                dp[i][j]=false;
            

        for (int i =0 ;i<size;i++)
        {
            dp[i][i]=true;
        }

        for (int l = 1;l<=size;l++)
        {
            for (int i =0;i<size-l;i++ )
            {
                if(s[i]!=s[i+l])
                    dp[i][i+l] = false;
                
                else if (i+1>i+l-1)
                    dp[i][i+l]=true;
                else 
                    dp[i][i+l]= dp[i+1][i+l-1];
            }


        }
        int maxLen = 1;
        int pos=0;
        for (int i =0 ;i<size;i++)
            for (int j = i;j<size;j++)
                if(dp[i][j]==true && maxLen<j-i+1)
                    {
                        pos=i;
                        maxLen = j-i+1;
                    }

        return s.substr(pos,maxLen);
    }
};