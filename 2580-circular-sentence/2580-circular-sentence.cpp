class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        stringstream s(sentence);
        vector<string> str;
        string word;
        
        while (s >> word) {
            str.push_back(word);
        }

        if (str.size() == 1 && str[0][0] == str[0].back())
            return true;

        for (int i = 0; i < str.size(); ++i) {
            int next = (i + 1) % str.size();
            if (str[i].back() != str[next][0]) {
                return false;
            }
        }

        return true;
    }
};
