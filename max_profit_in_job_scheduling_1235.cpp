

// Time Complexity O(n^2)
class Solution {
public:

    bool static compareInterval(const vector<int> &a,const vector<int>&b){
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>vec(n);


        for (int i =0;i<n;i++){
            vec[i].push_back(startTime[i]);
            vec[i].push_back(endTime[i]);
            vec[i].push_back(profit[i]) ;
        }
        sort(vec.begin(),vec.end(),compareInterval);

        vector<int> dp(n);
        dp[0]=vec[0][2];
        for (int i =1;i<n;i++){
            int maxTemp = vec[i][2];
            for (int j =0;j<i;j++){   
                if(vec[i][0]>=vec[j][1]){
                    maxTemp = max(maxTemp,vec[i][2]+dp[j]);
                }
            }
            dp[i]= maxTemp;
        }

        int maxAns = 0;
        for (auto i :dp) maxAns = max(i,maxAns);

        return maxAns;
        

    }
};