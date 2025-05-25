class Solution {
public:

    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int count[26][26];
        int len = 0;
        for(int i = 0;i<n;i++){
            string word = words[i];
            int a = word[0]-'a';
            int b = word[1] - 'a';
            if(count[a][b]>0){
                len += 4;
                count[a][b]--;
        }
        else{
            count[b][a]++;
        }
        }
        for(int i = 0;i<26;i++){
            if(count[i][i]>0){
                len += 2;
                break;
            }
        }
        
        return len;
    }
};