class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long maxScore = 0;
        int n = nums.size();
        priority_queue<int> pq;
        //sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int root = pq.top();
            maxScore += root;
            pq.pop();
            pq.push(ceil(root/3.0));
            
            k--;

        }
        return maxScore;
    }
};