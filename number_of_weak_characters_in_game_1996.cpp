class Solution {
public:

    bool static comp(const vector<int> &a , const vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        int n = properties.size();
        int minVal =properties[n-1][1];
        int ans = 0;

        for (int i =n-2;i>=0;i--){
            if(properties[i][1]<minVal){
                ans++;
            }
            else{
                minVal= properties[i][1];
            }
        }

        return ans;
    }
};





// All test cases not passing, one logical error
// class Solution {
// public:
//     int numberOfWeakCharacters(vector<vector<int>>& properties) {
//         sort(properties.begin(),properties.end());
//         int maxDef =  properties[properties.size()-1][1];
//         int numWeak =0;
//         int curNum = properties[properties.size()-1][0];
//         for (int i =properties.size()-2;i>=0;i--){
//             if(properties[i][1]<maxDef && curNum!=properties[i][0]){
//                 numWeak++;
//                 // curNum=properties[i][0];
//             }
//             else {
//                 maxDef = properties[i][1];
//             }
//         }
//         return numWeak;
//     }
// };

