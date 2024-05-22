class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int s,vector<bool>&inStack,vector<bool>&seen){
        if(inStack[s])
            return false;
        if(seen[s])
            return true;

        inStack[s] = true;
        seen[s] = true;
        for(auto i :graph[s]){
            if(!dfs(graph,i,inStack,seen))
                return false;
        }
        
        inStack[s] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& i :  prerequisites){
            graph[i[0]].push_back(i[1]);
        }
        vector<bool>inStack(numCourses,false);
        vector<bool>seen(numCourses,false);
        for(int i =0 ;i<numCourses;i++){
            if(!dfs(graph,i,inStack, seen)){
                return false;
            }
        }
        return true;
    }
};
