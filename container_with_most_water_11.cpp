

//As per the constraints on height[i] and n, the following solution 
// gets the answer in less than 1e9 operations per second hence it passes
// This solution is pseudo-linear time complexity
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxHeight =INT_MIN;
        int n = height.size();
        for (int i =0;i<n;i++){
            maxHeight= max(maxHeight,height[i]);
        }
        int overallMaxArea = 0;
        int curMaxArea = 0;
        for(int i=1;i<=maxHeight;i++){
            curMaxArea=INT_MIN;
            int start=0,end=n-1;
            while(start<end){
                int h = min(height[start],height[end]);
                if(h>=i){
                    curMaxArea=i*(end-start);
                    overallMaxArea=max(curMaxArea,overallMaxArea);
                    break;
                }
                else {
                    if(height[start]<i)start++;
                    if(height[end]<i)end--;
                }
            }
        }
        return overallMaxArea;

    }
};

//The following solutino is strictly linear time compleixty, just much less intuitive than the previous approach

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right =height.size()-1;
        int overallMax =INT_MIN;

        while(left<right){
            overallMax= max(overallMax,(right-left)*(min(height[left],height[right])));
            if(height[left]<=height[right]){
                left++;
            }
            else {
                right--;
            }
        }

        return overallMax;
    }
};