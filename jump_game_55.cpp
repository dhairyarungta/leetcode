// approximately O(n) time complexity (TBC)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool check = false;
        int i ;
        vector<int> pos;

        for ( i =0;i<nums.size();i++){
            if(nums[i]==0)
                pos.push_back(i);
        }
        if(pos.size()==0){
            return true;
        }

        for(int m = 0;m<pos.size();m++){
            int zeroIndex =pos[m];
            if(zeroIndex ==nums.size()-1) return true;
            
            int endIndex = 0;
            check = false;
            for (int i = zeroIndex;i>=endIndex;i--){
                if(nums[i]>zeroIndex-i){
                    check =true;
                }
            } 
            if(check==false){
                return false;
            }
            endIndex=zeroIndex+1;
        }

    return check;
    }


};


//o(n) Single Scan
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i =0;i<=maxReach && i<nums.size();i++){
            maxReach = max(maxReach,i+nums[i]);
        }
        return (maxReach>=nums.size()-1);
    }
};