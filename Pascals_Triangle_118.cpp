class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>a(numRows);
        for(int i =0;i<numRows;i++){
            for (int j =0;j<i+1;j++){
                if(j==0 || j==i){
                    a[i].push_back(1);
                }
                else {
                    a[i].push_back(a[i-1][j]+a[i-1][j-1]);
                                  }
            }
        }
        return a;
    }
};