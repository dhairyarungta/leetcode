class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char,int> mp;

        int st = 0, en = 0;
        int temp= 0;
        while (en<s.size()){
            mp[s[en]]++;
            temp++;
            if(mp[s[en]]>1){
                while(mp[s[en]]!=1){
                    mp[s[st]]--;
                    st++;
                    temp--;
                }
            }
            ans = max(ans, temp);
            en++;
        }

        return ans;
    }
};