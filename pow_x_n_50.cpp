// O(logn) time compelxity
// binomial exponentiation





// O(n) time comeplexity
// possibility of integer overflow
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return double(1);

        double ans = 1;
        for (int i =0;i<abs(n);i++){
            ans*=x;
        }
        if(n<0){
            return (1/ans);
        }
        else return ans;

        
    }
};