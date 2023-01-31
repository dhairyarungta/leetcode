//DP solution
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int ** dp = new int*[n+1];
        for (int i =0;i<=n;i++)dp[i]= new int[m+1];

        for (int i=0;i<=n;i++)dp[i][0]=i;
        for (int j =0;j<=m;j++)dp[0][j]=j;

        for (int i =1;i<=n;i++){
            for (int j =1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                } 
                else {
                    dp[i][j]= 1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }

        return dp[n][m];

    }
};

//Recursive solution
// Exponential Time compelxity
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0)
            return word2.size();

        if(word2.size()==0)
            return word1.size();

        if(word1[0]==word2[0])
            return minDistance(word1.substr(1),word2.substr(1));


        return 1+ min({minDistance(word1.substr(1),word2.substr(1)), minDistance(word1.substr(1),word2), minDistance(word1,word2.substr(1))});
    }
};