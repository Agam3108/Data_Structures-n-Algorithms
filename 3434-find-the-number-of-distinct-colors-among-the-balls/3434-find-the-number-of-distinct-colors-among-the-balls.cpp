class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       unordered_map<int, int> mpp; // Store the latest color of each bucket
        unordered_set<int> colorSet; 
        vector<int> result;
        for (const auto& query : queries) {
            int bucket = query[0];
            int color = query[1];
            if (mpp.count(bucket)) {
                int oldColor = mpp[bucket];
                if (oldColor != color) { 
                    mpp.erase(bucket);
                    bool stillPresent = false;
                    for (const auto& pair : mpp) {
                        if (pair.second == oldColor) {
                            stillPresent = true;
                            break;
                        }
                    }
                    
                    if (!stillPresent) {
                        colorSet.erase(oldColor);
                    }
                }
            }
            mpp[bucket] = color;
            colorSet.insert(color);
            result.push_back(colorSet.size());
        }
        return result;
    }
};