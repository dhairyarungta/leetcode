class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = cost.size();
    int totalgas = 0;
    int totalcost= 0;

    for (auto i: gas)totalgas+=i;
    for(auto i:cost )totalcost+=i;

    if(totalcost > totalgas)return -1;

    int curgas = 0;
    int curcost = 0;
    int index =0 ;

    for (int i =0;i<n;i++){
      curgas += gas[i];
      if (curgas - cost[i] < 0) {
        index = i + 1;
        curgas = 0;
      }
       else {
         curgas-=cost[i];
      }
    }

  return index;

    }
};