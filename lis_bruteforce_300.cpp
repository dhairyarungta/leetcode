#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recUtility(vector<int> & nums,int &maxTotalAns, int n ){
        if (n==1)
            return 1;

        int max_cur =1 ;

        for (int i =0;i<n-1;i++){
            if (recUtility(nums,maxTotalAns,i+1)>=max_cur && nums[n-1]>nums[i]){
                max_cur= recUtility(nums,maxTotalAns,i+1)+1;
            }
        }

        if (max_cur>maxTotalAns){
            maxTotalAns = max_cur;
        }
        return max_cur;
    }

    
    int lengthOfLIS(vector<int>& nums) {
        int max = 1 ;
        recUtility(nums, max, nums.size());
        return max;
    }

};