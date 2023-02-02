class Solution {
public:

    long long calcNCR(int n, int r ){

        if(r==0)
        return 1; 

        unsigned long long ans = 1;
        for(unsigned long long  i =0;i<r;i++){
            ans=(ans*(n-i))/(i+1);
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return calcNCR(m+n-2,min(n-1,m-1));
    }
};