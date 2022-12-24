class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long globalMax = INT_MIN;
        long long curMax = 0;
        //curMax has value of the max sum subarray ending at each index

        for (int i =0;i<nums.size();i++){
            curMax +=nums[i];
            globalMax= max(globalMax,curMax);
            if(curMax>=0){
            }   
            else{
                curMax =0;
            }
        }
        return globalMax;
    }
};



//code to print out the subarray as well
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int globalMax= INT_MIN;
        int curMax =0;
        int st=0, en=0, s=0;
        for (int i =0;i<n;i++){
            curMax+=nums[i];
            if(curMax>globalMax){
                globalMax=curMax;
                en = i;
                st = s;

            }
            
            if(curMax<0){
                curMax =0;
                s =i+1;
            }
        }
        for(int i=st;i<=en;i++) cout<< nums[i]<<" ";
        cout<<endl;

        return globalMax;
        
        }
};