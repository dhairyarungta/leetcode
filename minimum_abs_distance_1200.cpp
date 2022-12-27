class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>a;
        sort(arr.begin(),arr.end());
        int overallMin= INT_MAX;

        for (int i =0;i<arr.size()-1;i++){
            int curMin = arr[i+1]-arr[i];
            overallMin= min(curMin,overallMin);
        }

        for (int i =0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==overallMin){
                vector<int> temp(2);
                temp[0]=arr[i];
                temp[1]=arr[i+1];
                a.push_back(temp);
            }
        }
        return a;
    }
};