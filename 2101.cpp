class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, list<int>> graph;
        int n= bombs.size();
        for (int i = 0;i<n;i++)
        {   
            long long r = bombs[i][2];
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            for (int j =0 ;j<n;j++)
            {
               if(i!=j)
               {    
                   long long  x2 = bombs[j][0];
                   long long  y2 = bombs[j][1];
                   
                   
                   long long centreDistanceSquared = (x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2);
                   if(centreDistanceSquared<=(r*r))
                   {
                       graph[i].push_back(j);
                   }

               }

            }

        }
            int maxCount =0 ;
            for(int i =0 ;i<n;i++)
            {
                int count = dfs( i , graph);  
                maxCount = max(count, maxCount);
            }
        return maxCount;
    }

    int dfs (int i , unordered_map<int, list<int>>& graph)
    {
        unordered_set<int>visited;
        stack<int> s;
        s.push(i);
        visited.insert(i);
        while(!s.empty())
        {
            int cur = s.top();
            s.pop();
            for (auto j: graph[cur])
            {
                if(visited.count(j)==0)
                {
                    visited.insert(j);
                    s.push(j);
                }
            }   
        }
        
       return visited.size(); 
    }

};