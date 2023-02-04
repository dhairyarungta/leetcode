//Bit manipulation approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        // value of ans size is 2^n;
        int ansSize = 1<<n;

        for (int i = 0; i<ansSize;i++){
            vector<int> temp;
            for (int j =0;j<nums.size();j++){
                if((i>>j)&1){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//Iterative Solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        // cout<<ans.size()
        for (int i =0;i<nums.size();i++){
            int ansSize = ans.size();
            for (int j =0;j<ansSize;j++){
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};

// Recursive inspired from iterative approach
class Solution {
public:

    void helperf(vector<int> &nums, vector<vector<int>>& ans, int st ){
        if(st== nums.size()){
            ans.push_back({});
            return ;
        }
        helperf(nums,ans,st+1);
        
        int ansSize = ans.size();
        for (int k = 0;k<ansSize;k++){
            vector<int> temp = ans[k];
            temp.push_back(nums[st]);
            ans.push_back(temp);
         }
    


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helperf(nums, ans,0);
        return ans;
    }
};
