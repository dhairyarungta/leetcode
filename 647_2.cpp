class Solution {
public:
    int helper(string&s , int i , int j, int** a)
    {

        if(i>=j){
            a[i][j]=1;
            return 1;
        }
        if(a[i][j]!=-1)
        {
            return a[i][j];
        }
        int ans =0;
        if(s[i]==s[j])
            ans = helper(s,i+1,j-1,a);
    
        a[i][j]= ans;
        return ans;

    }

    int countSubstrings(string s) {
        int** a = new int*[s.size()];

        for (int i =0 ;i<s.size();i++)
            a[i]= new int[s.size()];

        for (int i =0 ;i<s.size();i++)
            for (int j =0 ;j<s.size();j++)
                a[i][j]=-1;

        int amt = 0;
        for (int i =0 ;i<s.size();i++)
            for (int j =i ;j<s.size();j++)
                amt+=helper(s,i,j,a);
        return amt;
    }
};


class Solution {
public:
    int countSubstrings(string s) {
        int count =0 ;
        int arr[s.size()][s.size()];
        for (int i =0 ;i<s.size();i++)
            for (int j= 0;j<s.size();j++)
                arr[i][j]=0;

        int ans = 0;
        for (int i =s.size()-1;i>=0;i--){
            
            for ( int j=i;j<s.size();j++){
                if(i>=j)
                {
                    arr[i][j]=1;
                }
                else if(i+1==j)
                {
                    arr[i][j]=s[i]==s[j]?1:0;
                }
                else{
                    arr[i][j]=s[i]==s[j]?arr[i+1][j-1]:0;
                }
                ans+=arr[i][j];
            }
            
        }
    return ans;
    }
};