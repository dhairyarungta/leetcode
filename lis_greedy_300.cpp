#include <bits/stdc++.h>
using namespace std;

class Solution {
public :
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subseq;
        subseq.push_back(nums[0]);
        for (int x : nums){
            //greedily add numbers that are greater than the ending number for the subseq
            //or replace the value of number at i if nums[j-1]<nums[i] && nums[i]<nums[j]
            auto it = lower_bound(subseq.begin(),subseq.end(),x);
            if (it == subseq.end()){
                subseq.push_back(x);
            }
            else{
                if (x<(*it)){
                    (*it) = x;
                }
            }
        }
        return subseq.size();
    }
};