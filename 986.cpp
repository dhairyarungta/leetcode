class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size();
        int n2 = secondList.size();
        int i = 0,j= 0; 
        vector<vector<int>>v;
        for(;i<n1 && j<n2;){

            int s = max(firstList[i][0],secondList[j][0]);
            int e = min(firstList[i][1],secondList[j][1]);
            if(e-s>=0){
                v.push_back(vector<int>{s,e});
            }
            firstList[i][1]<secondList[j][1]?i++:j++;
        }
        return v;
    }
};
