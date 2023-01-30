class Solution {
public:


    bool static comapreInterval(const vector<int>&v1, const vector<int> &v2){
        return v1[0]<v2[0];
    }


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        if (intervals.size()==0)
            return ans;

        sort(intervals.begin(),intervals.end(),comapreInterval);
        ans.push_back(intervals[0]);

        for (int i =1;i<intervals.size();i++){
            int start= intervals[i][0];
            int end = intervals[i][1];

            if(start<=(ans.back())[1]){
                vector<int> temp = {(ans.back())[0],max(end,(ans.back())[1])};  
                ans.pop_back();
                ans.push_back(temp);
            }
            else {
                ans.push_back(intervals[i]);
            }

        }

        return ans;
    }
};