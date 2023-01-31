

//Recursive solution
// Exponential Time compelxity
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0)
            return word2.size();

        if(word2.size()==0)
            return word1.size();

        if(word1[0]==word2[0])
            return minDistance(word1.substr(1),word2.substr(1));


        return 1+ min({minDistance(word1.substr(1),word2.substr(1)), minDistance(word1.substr(1),word2), minDistance(word1,word2.substr(1))});
    }
};