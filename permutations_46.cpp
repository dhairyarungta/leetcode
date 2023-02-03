class Solution {
public:
    void recPermute(vector<int> &nums,vector<vector<int>>& ans, int st, int en){
        if(st==en){
            ans.push_back(nums);
            return;
        }

        for (int i =st;i<=en;i++){
            swap(nums[i],nums[st]);
            recPermute(nums,ans,st+1,en);
            swap(nums[i],nums[st]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        recPermute(nums,ans,0,nums.size()-1);
        return ans;
    }
};