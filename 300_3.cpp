class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>sub;
        vector<int>subIndex;
        vector<int>trace(n,-1);
        for (int i=0;i<n;i++){
            if(sub.empty() || sub[sub.size()-1]<nums[i]){
                if(!sub.empty())
                    trace[i] = subIndex[sub.size()-1];
               sub.push_back(nums[i]) ;
               subIndex.push_back(i);
            }
            else {
                int idx = lower_bound(sub.begin(), sub.end(),nums[i])-sub.begin();
                if(idx>0)
                    trace[i]=subIndex[idx-1];
                sub[idx]=nums[i];
                subIndex[idx] = i;

            }
        }        
        vector<int>path;
        int t= subIndex [subIndex.size()-1];
        while(t!=-1){
            path.push_back(nums[t]);
            t = trace[t];

        } 
        reverse(path.begin(),path.end());
        return path.size();
    }
};
