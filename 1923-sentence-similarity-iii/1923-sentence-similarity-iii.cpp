class Solution {
public:
    vector<string> countWords(string str) {
        vector<string> words;
        string temp = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                if (!temp.empty()) words.push_back(temp);
                temp = "";
            } else {
                temp += str[i];
            }
        }
        if (!temp.empty()) words.push_back(temp); 
        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> sen1words = countWords(sentence1);
        vector<string> sen2words = countWords(sentence2);
        int n = sen1words.size();
        int m = sen2words.size();
        
        // Ensure sen1words is always the longer sentence
        if (n < m) {
            swap(sen1words, sen2words);
            swap(n, m);
        }

        // Try to match the prefix
        int left = 0;
        while (left < m && sen1words[left] == sen2words[left]) {
            left++;
        }

        // Try to match the suffix
        int right = 0;
        while (right < m && sen1words[n - right - 1] == sen2words[m - right - 1]) {
            right++;
        }

        return (left + right >= m);
    }
};
