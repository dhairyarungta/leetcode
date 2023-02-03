// O(logn) time complexity 
//O(1)space complexity
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = (m*n)-1;
        int startcol = 0,endcol=m-1;
        
        while(start<=end){
            int midcol = (startcol+endcol)/2;
            int numCount = (start+end)/2;
            int offset = numCount%n;

            if(numCount/n>(midcol)){
                midcol++;
            }
            cout<<matrix[midcol][offset]<<" ";
            if(matrix[midcol][offset]==target){
                return true;
            }
            else if(matrix[midcol][offset]<target){
                start=numCount+1;
                startcol = start/n;
            }
            else{
                end = numCount-1;
                endcol = end/n;
            }
        }
        return false;

    }
};

// O(n) time complexity
// O(n) space complexity

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>vec;
        int m = matrix.size();
        int n = matrix[0].size();

        int newsize= m*n;
        for (int i =0;i<m;i++){
            for (int j = 0;j<n;j++){
                vec.push_back(matrix[i][j]);
            }
        }
        return binary_search(vec.begin(),vec.end(),target);


    }
};

