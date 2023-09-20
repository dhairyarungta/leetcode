class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> stop;
        const int n = intervals.size();
        for(int i = 0;i<n;i++)
        {
            start.push_back(intervals[i][0]);
            stop.push_back(intervals[i][1]);

        }
        sort(start.begin(), start.end());
        sort(stop.begin(), stop.end());
        
        int curCount =0;
        int maxCount = 1;
        int s =1, e =0;

        while (s<n && e<n)
        {
            while (s<n && start[s]<stop[e])
            {
                s++;
            }
            maxCount = max(maxCount , s-e);
            e++;

        }

        return maxCount;
    }
};