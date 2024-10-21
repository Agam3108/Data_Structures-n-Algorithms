class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        // Base case: If we reach the end of the string, return 0 (no more
        // substrings to add)
        if (start == s.size()) return 0;

        int maxCount = 0;
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxCount = max(maxCount, 1 + backtrack(s, end, seen));
                seen.erase(substring);
            }
        }
        return maxCount;
    }

};