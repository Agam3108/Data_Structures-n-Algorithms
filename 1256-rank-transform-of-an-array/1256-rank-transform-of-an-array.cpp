class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(arr);
        vector<int> rank(n);
        sort(temp.begin(),temp.end());
        unordered_map<int,int> rankMap;
       int pos = 1;
        for(int i = 0;i<n;i++){
           if(rankMap.find(temp[i])==rankMap.end())
           rankMap[temp[i]] = pos++;
        }
        for(int i = 0;i<n;i++){
            rank[i] = rankMap[arr[i]] ;
        }
     return rank ;
    }   

};