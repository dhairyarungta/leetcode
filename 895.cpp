
class FreqStack {
private:
    unordered_map<int, int> m_freq;
    unordered_map<int, stack<int>> m_stack;
    int maxFreq = 0;

public:
    FreqStack() {}

    void push(int val) {
        m_freq[val]++;
        maxFreq = max(maxFreq, m_freq[val]);
        m_stack[m_freq[val]].push(val);
    }

    int pop() {
        int cur_top = m_stack[maxFreq].top();
        m_stack[maxFreq].pop();
        --m_freq[cur_top];

        if (m_stack[maxFreq].empty()) {
            m_stack.erase(maxFreq);
            --maxFreq;
        }
        return cur_top;
    }
};
