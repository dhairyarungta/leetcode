class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int arr[n+1][m+1];

        for (int i =0;i<=n;i++)arr[i][0]=0;
        for (int j=0;j<=m;j++)arr[0][j]=0;

        for (int i =1;i<=n;i++){
            for (int j =1;j<=m;j++){

                if(text1[i-1]==text2[j-1]){
                    arr[i][j]=1+arr[i-1][j-1];
                }
                else {
                    arr[i][j]= max({arr[i-1][j-1],arr[i-1][j],arr[i][j-1]});
                }

                // cout<<arr[i][j]<<" ";
            }
            // cout<<endl;
        }

        return arr[n][m];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()==0 || text2.size()==0)
            return 0;

        if(text1[0]==text2[0])
            return 1+longestCommonSubsequence(text1.substr(1),text2.substr(1));
        return max(longestCommonSubsequence(text1,text2.substr(1)),longestCommonSubsequence(text1.substr(1),text2));
    }
};