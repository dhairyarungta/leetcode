#include <bits/stdc++.h>
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        int n1 = slots1.size();
        int n2 = slots2.size();
        int i = 0, j= 0;
        for(;i<n1 && j<n2;){
            pair<int,int>p1 = slots1[i][0]<slots2[j][0]?pair{slots1[i][0],slots1[i][1]} : pair{slots2[j][0],slots2[j][1]};
            pair<int,int>p2  = slots1[i][0]>=slots2[j][0]?pair{slots1[i][0],slots1[i][1]} : pair{slots2[j][0],slots2[j][1]};
            int &diff_1 = slots1[i][0]<slots2[j][0] ? i :j;
            int &diff_2 = slots1[i][0]>=slots2[j][0]?i:j;
            int s = max(p1.first,p2.first);
            int e = min(p1.second,p2.second);
            int d = e-s;
            if(d>=duration){
                return vector<int>{s,s+duration};
            }

            if(p1.second>p2.second){
                diff_2++;
            }
            else if(p1.second<p2.second){
                diff_1++;
            }
            else {
                diff_1++;
                diff_2++;
            }

        }
        return vector<int>{};
    }
};
