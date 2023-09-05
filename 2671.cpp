class FrequencyTracker {
private :
    unordered_map<int,int> m_num; //number, freq
    unordered_map<int,int>m_freq; //freq,distinct number with same frequency
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        m_freq[m_num[number]]--;
        m_num[number]++;
        m_freq[m_num[number]]++;
    }
    
    void deleteOne(int number) {
        if(m_num[number]==0)
            return;

        m_freq[m_num[number]]--;
        m_num[number]--;
        m_freq[m_num[number]]++;

    }
    
    bool hasFrequency(int frequency) {
        return m_freq[frequency]==0?false:true;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */