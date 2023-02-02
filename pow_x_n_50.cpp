// O(logn) time compelxity
// binomial exponentiation

class Solution {
public:
    double recmyPow(double x, long long n) {
        if(n==0)
            return 1;

        int setBit = n%2;

        if(setBit==1){
            return x*recmyPow(x*x,n/2);
        }
        else return recmyPow(x*x,n/2);
        
    }

    double myPow(double x, int n){
        n = (long long)n;
        if(n==0)
            return double(1);
        double ans = recmyPow(x,abs(n));
        if(n<0)
            return  (1/ans);
        else 
        return ans;
    }
};


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