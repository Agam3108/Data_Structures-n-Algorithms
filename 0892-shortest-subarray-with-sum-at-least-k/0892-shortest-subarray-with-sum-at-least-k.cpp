class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
       
        long long  sum = 0;
        int minLen = INT_MAX;
        priority_queue<pair<long long,int>,vector<pair<long long,int>> ,greater <>> pq;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum>=k)
            minLen = min(minLen,i+1);
            while(!pq.empty() && sum - pq.top().first >= k){
                minLen = min(minLen,i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }
        
        return minLen == INT_MAX?-1:minLen;
    }
};