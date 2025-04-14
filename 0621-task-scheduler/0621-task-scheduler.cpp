class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        unordered_map<char,int> freq;
        priority_queue<int> pq;
        for(char task : tasks){
            freq[task]++;
        }
        for(const auto it : freq){
            pq.push(it.second);
        }
        int time = 0;
        while(!pq.empty()){
            int cycle = n+1 ;
            vector<int> remaining;
            while(cycle && !pq.empty()){
                int maxFreq = pq.top();
                pq.pop();
                if(maxFreq > 1)
                remaining.push_back(maxFreq - 1);
                ++time;
                --cycle;
            }
            for(int count : remaining)
            pq.push(count);
            if(pq.empty())
            break;
            time += cycle;
        }
        return time;
    }
};