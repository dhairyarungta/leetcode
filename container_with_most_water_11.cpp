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