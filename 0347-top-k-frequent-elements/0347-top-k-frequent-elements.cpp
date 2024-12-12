class Solution {
public:
static bool cmp(pair<int, int>& a, 
        pair<int, int>& b) 
{ 
    return a.second < b.second; 
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        vector<int> res;
        vector<pair<int,int>> valSortMap;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        for(const auto it : mp){
            valSortMap.push_back({it.first,it.second});
        }
      
        sort(valSortMap.begin(),valSortMap.end(),cmp);
          reverse(valSortMap.begin(),valSortMap.end());
          for(int i = 0;i<k;i++){
            res.push_back(valSortMap[i].first);
          }
       
        return res;
    }
};