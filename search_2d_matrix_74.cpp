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

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         int start = 0;
//         int end = (m*n)-1;
//         int startcol = 
//         while(start<=end){
//             int midcol = 
//         }

//     }
// };