class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, int destination, vector<vector<int>> &paths,vector<int> &current){
        if(node==destination){
            current.push_back(destination);
            paths.push_back(current);
            return;
        }
        current.push_back(node);
        for (auto i : graph[node]){
            dfs(graph,i, destination,paths,current);
            current.pop_back();
        }


    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>paths;
        vector<int>current;
        dfs(graph, 0,n-1,paths, current);
        return paths;  
    }
};
