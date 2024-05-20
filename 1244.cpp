class Leaderboard {
    using m_itr = std::multiset<int>::iterator;
    unordered_map<int,m_itr>a;//id, score iterator
    multiset<int>s ;//scores
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(a.contains(playerId)){
            int old_score = *(a[playerId]);
            score +=old_score;
            s.erase(a[playerId]);
            auto it  = s.insert(score);
            a[playerId]  = it;
            return;
        }
        auto it2 = s.insert(score);
        a.insert({playerId,it2});
    }
    
    int top(int K) {
        long sum = 0;
        auto it = s.rbegin();
        while(K--){
            sum+=*it;
            it++;
        }
        return sum;
    }
    
    void reset(int playerId) {
        if(!a.contains(playerId))
            return ;
        auto it = a[playerId];
        s.erase(it);
        it = s.insert(0);
        a[playerId] = it;
        return;
    }

};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
