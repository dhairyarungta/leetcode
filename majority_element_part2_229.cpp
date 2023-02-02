//O(n) time complexity
//O(1) space complexity



//O(nlgn) time complexity
//O(n) space complexity
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int count = nums.size()/3;

        for (auto i :nums){
            mp[i]++;
        }
        vector<int>ans;
        for (auto [i,j]:mp){
            if(j>count)ans.push_back(i);
        }
        
        return ans;
    }
};