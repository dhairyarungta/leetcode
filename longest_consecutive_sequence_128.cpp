class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto i : nums) st.insert(i);

        int longestNum = 0;
        // int temp = 0;

        for (auto i : st){
            int temp =1;
            if(st.count(i-1)==0){
                int j =i+1;
                while(st.count(j++)!=0){
                    temp++;
                }
            }

            longestNum = max(longestNum,temp);
        }

    return longestNum;
        
    }

};