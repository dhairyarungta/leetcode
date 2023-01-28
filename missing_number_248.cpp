class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (auto i : nums) sum+=i;

        long long total = (n*(n+1))/2;
        return  total-sum;
    }
};