//O(n) time complexity 
//O(1) space complexity




//O(nlogn) time complexity 
//O(1) space complexity
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        pair<int,int> ans ={nums[0],1} ;
        pair<int,int> cur = {nums[0],1};


        for (int i =1;i<nums.size();i++){
            if(cur.first==nums[i]){
                cur.second++;

                if(cur.second>ans.second){
                    ans={cur.first, cur.second};
                }
            }

            else {
                cur={nums[i],1};
            }

        }
        return ans.first;


        }
};