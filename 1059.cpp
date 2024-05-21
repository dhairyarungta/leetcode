ass Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<bool>&seen , vector<bool>&inStack,int i, int dest){
        if(graph[i].empty())
            return i ==dest;
        if(inStack[i]==true){
            return false;
        }
        if(seen[i] == true){
            return true;
        }

        seen[i] = true;
        inStack[i] = true;

        for(auto neigh : graph[i]){
            if(!dfs(graph,seen,inStack,neigh,dest)){
                return false;
            }
        }

        inStack[i] = false;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        

        vector<vector<int>>graph(n);
        for(int i =0 ;i<edges.size();i++){
            int  s = edges[i][0];
            int e = edges[i][1];
            graph[s].push_back(e);
        }
        
        if(!graph[destination].empty()){
            return false;
        }
        vector<bool>seen(n,false);
        vector<bool>inStack(n,false);
        
        return dfs(graph,seen,inStack,source,destination);
        
    }
};
