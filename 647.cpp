class Solution {
public:

    bool checkPalindrome (string s)
    {
        int left = 0, right = s.size()-1;
        while(left<right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count =0;
        for (int i =0 ;i<s.size();i++)
        {
            for (int len=s.size()-i;len>0;len-- )
            {
                if(checkPalindrome(s.substr(i,len))==true)
                    count++;
            }
        }
        return count ;
    }
};