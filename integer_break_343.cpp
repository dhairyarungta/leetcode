// Optimised dynamic programming solution

class Solution {
public:
    int integerBreak(int n) {
        if(n==2){
            return 1;
        }
        if(n==3)    
            return 2;
        
        int power_three = (int)n/3;
        int remainder = n%3;

        if(remainder==1){
            power_three--;
            remainder=4;
        }
        else if (remainder ==0){
            remainder = 1;
        }
        return (pow(3,power_three)*remainder);   

            }
};


// Recursive Solution, bad time compelxity 
class Solution {
public:

    int integerBreakRec(int n, vector<int>a) {

        if (a[n]!=-1)
            return a[n];


        if(n==1)
         return 1;

        if(n==2)
         return 1;


        int ans = -999;
        for (int i =1;i<n;i++){
            ans = max({ans, integerBreakRec(n-i,a)*integerBreakRec(i,a), i*(n-i),integerBreakRec(n-i,a)*i,integerBreakRec(i,a)*(n-i)});
        }

        a[n]=ans;

        return ans;
    }


    int integerBreak(int n){
        vector<int> a(n+1);
        for (int i = 0;i<=n;i++)a[i]=-1;
        return integerBreakRec(n, a);

    }

};