class Solution {
public:
    int compress(vector<char>& chars) {
         int n = chars.size();
    if (n == 0) return 0;
    string res = "";
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (chars[i] == chars[i - 1]) {
            count++;
        } else {
            res += chars[i - 1];
            if (count > 1) {
                res += to_string(count);
            }
            count = 1;
        }
    }
    res += chars[n - 1];
    if (count > 1) {
        res += to_string(count);
    }

    chars.clear();
    for (int i = 0; i < res.length(); i++) {
        chars.push_back(res[i]);
    }
    
    return chars.size();
    }
};