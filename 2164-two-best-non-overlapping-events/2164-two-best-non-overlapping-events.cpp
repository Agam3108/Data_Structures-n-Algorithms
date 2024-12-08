class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
          sort(events.begin(), events.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        int maxSum = 0;
        int maxSingleValue = 0; 
        
        for (auto& event : events) {
            int start = event[0];
            int end = event[1];
            int value = event[2];
            while (!pq.empty() && pq.top().first < start) {
                maxSingleValue = max(maxSingleValue, pq.top().second);
                pq.pop();
            }
            maxSum = max(maxSum, value + maxSingleValue);
            pq.push({end, value});
        }
        
        return maxSum;
    }
};