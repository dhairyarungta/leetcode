//disjoint quick union, with rank and path compression
class DisjointSet{
    public:
    vector<int>root, rank;
    int n;
    vector<vector<int>>&edges;
    DisjointSet(int n, vector<vector<int>>&edges):n(n),root(vector<int>(n)),
    rank(vector<int>(n,1)),edges(edges){
        for (int i =0;i<n;i++){
            root[i]=i;
        }
    }

    int find(int x){
        if(x==root[x])
            return x;

        return root[x] = find(root[x]);
    }

    bool union_func(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                root[rootY]=rootX;

            }
            else if(rank[rootX]<rank[rootY]){
                root[rootX]=rootY;
            }
            else {
                root[rootX]=rootY;
                rank[rootY] ++;
            }
        }else 
            return true;
        
        return false;
    }
};
class Solution {

public:
    bool validTree(int n, vector<vector<int>>& edges) {
	if(edges.size()!=n-1)
		return false;
        int numComp = n;
        DisjointSet dsu(n,edges);
        for(auto i:edges){
            if(dsu.union_func(i[0],i[1]))
                return false;
            else 
                numComp--;
        }
        return numComp==1;
    }
};
