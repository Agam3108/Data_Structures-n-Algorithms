class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans ;
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++){
            pq.push({abs(x-arr[i]),arr[i]});
            if(pq.size()>k)
            pq.pop();
        }
        while(pq.size()>0){
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};