//interative dfs solution instead of disjoint union
class Solution {
public:
    stack<int>dfs_stack;
    set<int>seen_set;
    vector<vector<int>>adj_list;
    int countComponents(int n, vector<vector<int>>& edges) {
        adj_list.resize(n);
        for (auto i:edges){
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        int numComp =0;
        for (int i =0;i<n;i++){
        if(seen_set.contains(i))
            continue;    
         
        numComp++;
        dfs_stack.push(i);
        while(!dfs_stack.empty()){
            int node = dfs_stack.top();
            dfs_stack.pop();
            seen_set.insert(node);
            for(auto neigh:adj_list[node]){
                if(!seen_set.contains(neigh)){
                    dfs_stack.push(neigh);
                }
            }
        }
        }
        return numComp;
    }
}; 
