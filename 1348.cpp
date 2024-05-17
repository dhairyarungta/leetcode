class TweetCounts {
    std::unordered_map<string,multiset<int>>mp;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        if(mp.contains(tweetName)){
            mp[tweetName].insert(time);
        }
        else{
           mp.insert({tweetName,multiset<int>{time}}) ;
        }
        
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int diff = 0;
        if(freq=="minute")
            diff = 60;
        if(freq=="hour")
            diff = 3600;
        if(freq=="day")
            diff = 84600;
        vector<int> returnVec;
        if(mp.contains(tweetName)) {
            multiset<int>&timeStamps = mp[tweetName];
            auto it_start = std::lower_bound(timeStamps.begin(), timeStamps.end(),startTime);
            auto it_end = std::upper_bound(timeStamps.begin(), timeStamps.end(),endTime);
    
            int curEnd = startTime+diff-1;
            int intervalCount = 0;
            auto it = it_start ;

            while(curEnd<=endTime+diff-1){
                if(it == it_end){
                    returnVec.push_back(0);
                }
                else {
                    for(;it!=it_end && *it<=curEnd;it++){
                        if(*it<=curEnd){
                            intervalCount++;
                        }
                    }
                    returnVec.push_back(intervalCount);
                    intervalCount =0;
                }

                curEnd+=diff;
            }
        }
        return returnVec;

    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
