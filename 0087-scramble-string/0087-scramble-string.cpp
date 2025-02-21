class Solution {
public:
unordered_map<string, bool> memo;
    bool isScramble(string s1, string s2) {
       if (s1 == s2) return true;
        int n = s1.length();
        if (n <= 1) return false;

        string key = s1 + "_" + s2;
        if (memo.find(key) != memo.end()) return memo[key];
        vector<int> count(26, 0);
        for (char c : s1) count[c - 'a']++;
        for (char c : s2) count[c - 'a']--;
        for (int i : count) if (i != 0) return memo[key] = false;

        for (int i = 1; i < n; i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
                (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};