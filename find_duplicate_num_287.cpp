
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast= 0;
        int slow = 0;
        int n = nums.size();
        int cycleEntry = -1;

        do{
            fast=nums[nums[fast]];
            slow = nums[slow];
        }
        while (fast!=slow);

        slow= 0;

        while(fast!=slow){
            fast= nums[fast];
            slow = nums[slow];
        }
        cout<< fast<<" "<<slow;

        return fast;

    }
};


// O(n lgn) //modifies original array 
//better solution using Floyd's algorithm
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool check = false;
        int i ;
        for ( i =0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
            break;

        }

        return nums[i];
    }
};