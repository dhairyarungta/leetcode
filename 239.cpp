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


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i =0 ;i<nums.size();i++)
        {
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            while(dq.front()<i-k+1)
                dq.pop_front();

            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};