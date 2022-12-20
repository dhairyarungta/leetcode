// Time O(n^2)
// Space O(n)


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> dpTable(nums.size());
        if (nums.size()==0)
            return 0;

        dpTable[0]=1;
        int overallMaxAns = 1 ;
        for (int i =1;i<nums.size();i++){
            int curMax = 1 ;
            for (int j =0;j<i;j++){
                if (curMax<=dpTable[j] && nums[j]<nums[i]){
                    curMax= dpTable[j]+1;
                }
            }
            dpTable[i]= curMax;
            if (curMax>overallMaxAns){
                overallMaxAns= curMax;
            }
        }

        return overallMaxAns;
    }
};      