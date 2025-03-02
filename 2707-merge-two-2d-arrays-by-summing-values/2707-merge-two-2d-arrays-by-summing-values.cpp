class Solution {
public:
void removeDuplicateVectors(std::vector<std::vector<int>>& vecOfVec) {
    std::set<std::vector<int>> uniqueVecs;
    std::vector<std::vector<int>> result;

    for (const auto& vec : vecOfVec) {
        if (uniqueVecs.find(vec) == uniqueVecs.end()) {
            uniqueVecs.insert(vec);
            result.push_back(vec);
        }
    }
    vecOfVec = result;
}
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> mergedArr;
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i = 0;i<n;i++){
            mp1.insert({nums1[i][0],nums1[i][1]});
        }
         for(int i = 0;i<m;i++){
            mp2.insert({nums2[i][0],nums2[i][1]});
        }
        for(int i = 0;i<n;i++){
            int x = nums1[i][0];
            int y = nums1[i][1];
            int sum = 0;
            if(mp2.find(x)!=mp2.end())
            {
                 sum = y+mp2[x];
                 mp2.erase(x);
            }
            else
            sum = y;
           mergedArr.push_back({x,sum});
        }
         for(int i = 0;i<m;i++){
            int x = nums2[i][0];
            int y = nums2[i][1];
            int sum = 0;
            if(mp1.find(x)!=mp1.end())
            {
                 sum = y+mp1[x];
                 mp1.erase(x);
            }
            else
            sum = y;
           mergedArr.push_back({x,sum});
        }
        for(const auto it : mp1){
            mergedArr.push_back({it.first,it.second});
        }
        for(const auto it : mp2){
            mergedArr.push_back({it.first,it.second});
        }
        sort(mergedArr.begin(),mergedArr.end());
        removeDuplicateVectors(mergedArr);
        return mergedArr ;
    }
};