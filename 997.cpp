ass Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int>a(n+1,0);
        vector<int>b(n+1,0);

        for(auto& i : trust){
            if(i[0]==i[1])
                continue;

            a[i[0]]++;
            b[i[1]]++; 
        }
        for (int i =1 ;i<=n;i++){
            if(a[i] == 0 && b[i] == n-1)
                return i ;
        }
        return -1;
    }
};
