class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int ans = 0;
        int n = g.size();
        int m = s.size();
        if (m == 0)
            return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int top = 0, bottom = 0;
        while (top < n && bottom < m) {
            if (g[top] <= s[bottom]) {
                top++;
                ans++;
            }
            bottom++;
        }

        return ans;
    }
};