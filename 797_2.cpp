class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, int destination, vector<vector<int>> &paths,vector<int> &current){
        std::stack<pair<int,int>>st;//child,parent
        vector<bool> seen(graph.size(),false);
        st.push({node,node});
        while(!st.empty()){
            pair<int,int> currentNode = st.top();
            st.pop();
            while(!current.empty()&&current.back()!=currentNode.second){
                current.pop_back();
            }
            //seen[current] = true;
            current.push_back(currentNode.first);
            if(currentNode.first == destination){
                paths.push_back(current); 
                continue;
            }  
            for (auto i : graph[currentNode.first]){
                //if(seen[i] == false)
                 pair p{i,currentNode.first}   ;
                    st.push(p);
            }
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

