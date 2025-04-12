class Solution {
public:
static bool cmp(pair<char, int>& a, 
        pair<char, int>& b) 
{ 
    return a.second > b.second; 
} 

    string frequencySort(string s) {
         unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), cmp);
        string ans = "";
        for (auto& [ch, freq] : vec) {
            ans += string(freq, ch);
        }

        return ans;
    }
};