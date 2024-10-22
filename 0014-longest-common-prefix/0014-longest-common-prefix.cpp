class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int first = 0;
        string s = strs[first];
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < s.size() && j < strs[i].size()) {
                if (s[j] != strs[i][j])
                    break;
                else
                    j++;
            }
            s = s.substr(0, j);
            if (s.empty())
                return "";
        }

        return s;
    }
};