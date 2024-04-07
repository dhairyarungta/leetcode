class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int destination = (int)(graph.size())-1;
        vector<vector<int>>paths;
        unordered_map<int, vector<vector<int>>>memo;
        std::function<vector<vector<int>>(int)>func  = [&](int curNode){
            vector<vector<int>>results;
            if(memo.contains(curNode))return memo[curNode];
            if(curNode == destination){
                results.push_back(vector<int>{curNode});
            }
            else{
                for(auto nextNode : graph[curNode]){
                    for (auto& path : func(nextNode)){
                       vector<int>newPath{curNode} ;
                       newPath.insert(newPath.end(),path.begin(),path.end());
                       results.push_back(newPath);

                    }

                }
                
            }
            memo[curNode] = results;
            return results;
        };


        return func(0);
    }
};
