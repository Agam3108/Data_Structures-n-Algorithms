class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        stack<string> st;
        stringstream str(s);
        string word;
        while(str>>word){
            st.push(word);
        }
        string ans = "";
        while(!st.empty()){
            string wrd = st.top();
            st.pop();
            ans = ans + wrd + " ";
        }
        ans.pop_back();
        return ans;
    }
};