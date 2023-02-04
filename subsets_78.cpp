//Iterative Solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        // cout<<ans.size()
        for (int i =0;i<nums.size();i++){
            int numSize = ans.size();
            for (int j =0;j<numSize;j++){
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};



// class Solution {
// public:

//     void recFindSubsets(vector<int>&nums, vector<vector<int>>& vec, int st, int en){
//         if(st==en){
//             return ;
//         }

        

//     }
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>vec;
//         recFindSubsets(nums,vec,0,nums.size());
//         return vec;

//     }
// };