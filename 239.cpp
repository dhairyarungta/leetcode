class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> st;
        for (int i =0 ;i<k;i++) 
        {
            st.insert(nums[i]);
        }

        int maxTemp =*(st.rbegin()) ;
        ans.push_back(maxTemp);
        for(int i =k;i<nums.size();i++)
        {
            st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            maxTemp=*(st.rbegin());
            ans.push_back(maxTemp);
        }
        return ans;
    }
};