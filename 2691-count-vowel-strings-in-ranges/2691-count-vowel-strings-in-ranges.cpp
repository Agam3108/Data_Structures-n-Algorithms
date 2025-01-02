class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> ans(m);
        set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int sum = 0;
        vector<int> prefixSum(n);
        for(int i = 0;i<n;i++){
            string word = words[i];
            int len = word.length();
            if(st.find(word[0])!=st.end() && st.find(word[len-1])!=st.end())
            sum++;
            prefixSum[i] = sum;

        }
        for(int i =0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==0)
            ans[i] = prefixSum[r];
            else
            ans[i] = prefixSum[r]-prefixSum[l-1];
        }
        return ans;
    }
};