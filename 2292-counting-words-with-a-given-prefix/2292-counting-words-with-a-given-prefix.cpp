class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            string word = words[i];
            int m = word.length();
            string str = "";
            for(int j = 0;j<m;j++){
                str += word[j];
                if(str==pref)
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};