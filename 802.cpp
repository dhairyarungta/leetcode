class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<bool>&inStack, set<int>&seen, int i){
        if(inStack[i] == true){
            return false;
        } 
        if(seen.contains(i)){
            return true;
        }
        seen.insert(i);
        inStack[i] = true;
        
        for(int j = 0;j<graph[i].size();j++){
            if(!dfs(graph,inStack, seen,graph[i][j]))
                return false;
        }

        inStack[i] = false;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>safe;
        set<int>seen;
        
        vector<bool>inStack(n,false);
        for(int i =0;i<n;i++){
            dfs(graph,inStack,seen,i);
        }
        for(int i=0;i<n;i++){
            if(!inStack[i])
                safe.push_back(i);
        }
        return safe;
    }
};
