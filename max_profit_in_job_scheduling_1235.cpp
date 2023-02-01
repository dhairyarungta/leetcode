//DP solution 
//Time Complexity O(nlog_n)
class Solution {
public:
    bool static compareInterval(const vector<int> &a,const vector<int>&b){
        return a[1]<b[1];
    }
    bool static lower_bound_compare(const vector<int>&a , const int &b){
        return a[1]<b;
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

        map<int, int> dp;
        dp[0]=0;
        for (int i =0;i<n;i++){
            auto jobTimeIter=prev(dp.upper_bound(vec[i][0]));
            int curVal = jobTimeIter->second+vec[i][2];
            if(curVal>dp.rbegin()->second){
                dp[vec[i][1]]= curVal;
            }
        }
        int maxAns = 0;
        for (auto [i,j] :dp) maxAns = max(j,maxAns);
        return maxAns;
    }
};
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