// O(n) time complexity

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool check = false;
        int n = nums.size();
        for(int i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                int j;
                bool swapDone = false;
                int index = i;
                int num = nums[i-1];
                int curMin = nums[i];
                for (j=i;j<n;j++){
                    if(nums[j]<=curMin && nums[j]>num){
                        curMin=nums[j];
                        index = j;
                    }
                }
                swap(nums[index],nums[i-1]);
                check = true;
                int p = i,q=n-1;
                while(p<q){
                    swap(nums[p],nums[q]);
                    p++; q--;
                }
                break;
            }
        }
        if(check==false){
            sort(nums.begin(),nums.end());
        }
    }
};