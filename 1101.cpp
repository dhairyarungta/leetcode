class unionset{
public:
    int n;
    vector<int>rank;
    vector<int>root;
    unionset(int n):n(n),rank(vector<int>(n,1)),root(vector<int>(n)){
        for (int i =0;i<n;i++)
            root[i]=i;
    }

    int find(int x){
        int node = x;
        while(node!=root[node])       
            node=root[node];
        
        while(x!=node){
            int oldroot = root[x];
            root[x] = node;
            x = oldroot;
        }
        return node;
    }
    bool union_func(int x , int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY)
            return false;
        else {
            if(rank[rootX]==rank[rootY]){
                rank[rootX]++;
                root[rootY]=rootX;
            }
            else if(rank[rootX]>rank[rootY]){
                root[rootY] = rootX;
            }
            else {
                root[rootX] =rootY;
            }
            return true;
        }
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        int size = logs.size();
        int numComp = n;
        if(size<n-1)
            return -1;
        unionset dsu(n);
        for(int i = 0;i<logs.size();i++){
            if(dsu.union_func(logs[i][1],logs[i][2])){
                numComp--;
            }

            if(numComp==1)
                return logs[i][0];
        }
        return -1;
            
    }
};
