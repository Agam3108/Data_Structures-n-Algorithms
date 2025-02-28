class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
       // stack<string> st;
        stringstream str(s);
        string word;
        string ans = "";
        while(str>>word){
            reverse(word.begin(),word.end());
            ans = ans + word + " ";
        }
      /*  
        while(!st.empty()){
            string wrd = st.top();
            st.pop();
            ans = ans + wrd + " ";
        }
        ans.pop_back(); */
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};