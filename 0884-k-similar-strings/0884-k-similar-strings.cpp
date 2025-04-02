class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        int n = s1.size();
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        
        q.push({s1, 0});
        visited.insert(s1);

        while (!q.empty()) {
            auto [cur, swaps] = q.front();
            q.pop();

            int i = 0;
            while (i < n && cur[i] == s2[i]) i++; // Find first mismatch
            
            for (int j = i + 1; j < n; j++) {
                if (cur[j] == s2[i] && cur[j] != s2[j]) { // Valid swap
                    string next = cur;
                    swap(next[i], next[j]);
                    
                    if (next == s2) return swaps + 1;
                    if (!visited.count(next)) {
                        q.push({next, swaps + 1});
                        visited.insert(next);
                    }
                }
            }
        }
        return -1; // Should never reach here
    }
};
