class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        map<string, int> mp;
        if(s.size()<10)
            return ans;
        for (int i =0 ;i<=s.size()-10;++i)
        {   
            // cout<<s.substr(i,10)<<" ";
            // if(mp[s.substr(i,10)]>1)
            // {
            //     ans.push_back(s.substr(i,10));
            //     mp[s.substr(i,10)] = INT_MIN;
            //     // cout<<"in";
            // }
            mp[s.substr(i,10)]++;
        }

        for (auto [i,j]:mp)
        {
            if(j>1)
                ans.push_back(i);
        }
        return ans;
    }
};
