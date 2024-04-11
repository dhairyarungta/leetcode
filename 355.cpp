class Twitter {
public:
    unordered_map<int,unordered_set<int>>followMap;//userId,followerId
    vector<pair<int,int>>tweets;//userId, tweetId
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto& following = followMap[userId];
        vector<int>feed;
        for (auto it = tweets.rbegin();it!=tweets.rend();it++){
            if(it->first==userId || following.contains(it->first)){
                feed.push_back(it->second);
            }
            if(feed.size()==10) break;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);    
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].contains(followeeId)){
            followMap[followerId].erase(followeeId);
        }    
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
