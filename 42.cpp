class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right =height.size()-1;
        int leftmax = INT_MIN, rightmax = INT_MIN;
        int amt =0 ;
        while(left<=right)
        {
            leftmax= max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if(leftmax<rightmax)
            {   
                amt+=leftmax-height[left];
                left++;

            }
            else 
            {
                amt+=rightmax-height[right];
                right--;
            }
            
        }
        return amt;
    }
};