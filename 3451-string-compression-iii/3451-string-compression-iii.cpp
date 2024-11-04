class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string comp = "";
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1] && count!=9) {
                count++;
            }
            else {
               /* if(count == 9){
                    comp += to_string(count) + word[i - 1];
                    count = 1;
                } */
                comp += to_string(count);
                comp += word[i - 1];
                count = 1;
            }
        }
        if (count >= 1) {
            comp += to_string(count);
        }
        comp += word[n - 1]; 
        return comp;
    }
};