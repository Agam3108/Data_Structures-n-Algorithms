class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;  

        vector<int> res  ;
        
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                res.push_back(i);
            }
        }

        if (res.size() != 2) return false;
        int i = res[0], j = res[1];
        swap(s1[i], s1[j]);
        
        return s1 == s2;
    }
};
