//brute force cubic time complexity
class Solution {
    int rowSize;
    int colSize;
public:



    int recursiveHelper(int row, int col,vector<vector<char>>& matrix)
    {
        if(row==rowSize || col==colSize)
            return 0;
        if(matrix[row][col]=='0')
            return 0;
       return min(recursiveHelper(row+1, col,matrix),min(recursiveHelper(row+1, col+1,matrix),recursiveHelper(row, col+1,matrix)))+1;


    }
    int maximalSquare(vector<vector<char>>& matrix) {
        rowSize = matrix.size();
        if(rowSize!=0)
            colSize=matrix[0].size();
        else 
            return 0;
        int maxSize = 0;
        for (int i =0;i<rowSize;i++)
        {
            for (int j = 0;j<colSize;j++)
            {
                if(matrix[i][j]=='1')
                    maxSize = max(maxSize,recursiveHelper(i,j,matrix));
            }
        }    
        return maxSize*maxSize;
    }
};
