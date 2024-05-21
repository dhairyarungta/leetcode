class Solution {
public:
    bool dfs(vector<vector<int>>&g,int s){
        
        set<int>inStack;
        set<int>seen;
        stack<int>st;

        // inStack.insert(s);
        // seen.insert(s);
        st.push(s);

        while(!st.empty()){
            int cur = st.top();
            if(!inStack.contains(cur)){
                inStack.insert(cur);
                for(auto i : g[cur]){
                    if(inStack.contains(i))
                        return false;
                    if(!seen.contains(i)){
                        st.push(i);
                    }
                }
            } 
            else{
                st.pop();
                inStack.erase(cur);
                seen.insert(cur);
            
            }
        }

        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        for(auto i : prerequisites){
            g[i[0]].push_back(i[1]);
        }
        set<int>seen;

        for(int i = 0;i<numCourses;i++){
            if(!dfs(g,i))
                return false;
        }
        return true;
    }
};
