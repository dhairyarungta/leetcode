class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long globalMax = INT_MIN;
        long long curMax = 0;
        //curMax has value of the max sum subarray ending at each index

        for (int i =0;i<nums.size();i++){
            curMax +=nums[i];
            globalMax= max(globalMax,curMax);
            if(curMax>=0){
            }   
            else{
                curMax =0;
            }
        }
        return globalMax;
    }
};