class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        vector<string> box;
        unordered_set<string> st;
        if(numFriends==1)
        return word;
        if( n == numFriends){
            sort(word.begin(),word.end());
            string s(1,word[n-1]);
            return s;
        }
        for(int i = 0;i<n;i++){
            string str = word.substr(i,min(n-i,n-numFriends+1));
            if(st.find(str)==st.end()){
                box.push_back(str);
                st.insert(str);
            }
        }
        sort(box.begin(),box.end());
        return box[box.size()-1];
    }
};