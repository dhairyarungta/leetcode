//quick union with rank and path compression
class Solution {
    int n;
    vector<int>root;
    vector<int>rank;
public:
    int find (int x){
        if(root[x]==x)
            return x;

        return root[x] = find(root[x]);    
    }
    void union_func(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            if(rank[rootX]==rank[rootY]){
                root[rootX]=rootY;
                rank[rootY]++;
            }
            else if(rank[rootX]>rank[rootY]){
                root[rootY]=rootX;        
            }
            else {
                root[rootX] =rootY;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected){
        n = isConnected.size();
        root.resize(isConnected.size());
        for(int i =0;i<n;i++){
            root[i]=i;
        }
        rank.assign(isConnected.size(),1);
        for (int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j]==1)
                    union_func(i,j);
            }
        }
        for (auto i:root)
            cout<<i<<" ";
        int numProv = 0;
        set<int>s;
        for (int i =0;i<n;i++){
            int root = find(i);
            if(!s.contains(root)){
                s.insert(root);
                numProv++;
            }

        }
        return numProv;
    }
};
