class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int>q;
        unordered_set<int>seen;

        q.push(0);
        seen.insert(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto i :rooms[cur]){
                if(!seen.contains(i)){
                    seen.insert(i);
                    q.push(i);
                }
            }
        }
        if(seen.size()<rooms.size())
            return false;
        else 
            return true;
    }
};
