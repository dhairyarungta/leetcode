class UnionSet{
public:
    int n;
    vector<int>root;
    vector<int> rank;
    UnionSet(int n):n(n),root(vector<int>(n)),rank(vector<int>(n,1)){
        for (int i=0;i<n;i++)
            root[i]=i;
    }

    int find(int x){
        int node =x ;
        while(root[node]!=node)
            node =root[node];
        
        while(x!=node){
            int oldroot = root[x];
            root[x]=node;
            x = oldroot;
        }
        return node;
    }

    bool union_func(int x, int y){
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
        else {
            return false;
        }
        return true;
    }

};
class Solution {

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionSet dsu(n);
        int numComp = n;
        for (auto i:edges){
            if(dsu.union_func(i[0],i[1])){
                numComp--;        
            }
        }
    return numComp;
    }
};
