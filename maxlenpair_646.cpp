class Solution {
public:
// greedy algorithm
    static bool cmpFun( vector<int> &v1,  vector<int> &v2){
        return (v1[1]<v2[1]);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmpFun);
        vector<int> lastPair = pairs[0];
        int len = 1 ;

        for (int i =1;i<pairs.size();i++){
            if (pairs[i][0]>lastPair[1]){
                len++;
                lastPair = pairs[i];
            }
        }
        return len;
    }
};