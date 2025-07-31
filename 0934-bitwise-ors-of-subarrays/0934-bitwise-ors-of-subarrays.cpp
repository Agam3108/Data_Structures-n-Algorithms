class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
         vector<int> s; 
        int l = 0;
        for (int a : arr) 
        { 
            int r = s.size(); 
            s.push_back(a);  
            for (int i = l; i < r; ++i) 
            {
                int v = s[i] | a;
                if (v != s.back()) 
                { 
                    s.push_back(v);
                }
            }
            l = r;
        }
        unordered_set<int> unique(s.begin(), s.end());
        return unique.size();
    }
};