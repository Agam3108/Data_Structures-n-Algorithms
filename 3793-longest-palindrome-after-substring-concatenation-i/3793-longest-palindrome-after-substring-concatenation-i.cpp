class Solution {
public:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {
        int maxLen = 0;
        int n = s.size(), m = t.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string s_sub = s.substr(i, j - i + 1);
                for (int k = 0; k < m; k++) {
                    for (int l = k; l < m; l++) {
                        string t_sub = t.substr(k, l - k + 1);
                        string combined = s_sub + t_sub;
                        if (isPalindrome(combined)) {
                            maxLen = max(maxLen, (int)combined.size());
                        }
                    }
                }
                if (isPalindrome(s_sub)) {
                    maxLen = max(maxLen, (int)s_sub.size());
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                string t_sub = t.substr(i, j - i + 1);
                if (isPalindrome(t_sub)) {
                    maxLen = max(maxLen, (int)t_sub.size());
                }
            }
        }

        return maxLen;
    }
};
