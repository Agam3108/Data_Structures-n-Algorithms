class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        vector<int> freq(26, 0); 
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result = "";
        int prevCount = 0; 
        int prevChar = -1; 

        for (int i = 25; i >= 0;) { 
            if (freq[i] == 0) {
                i--; 
                prevCount = 0; 
                continue;
            }

            // If the current character is the same as the last used
            if (prevChar == i) {
                int j = i - 1;
                while (j >= 0 && freq[j] == 0) j--;
                if (j < 0) break;
                result += (char)(j + 'a');
                freq[j]--;
                prevChar = j;
                prevCount = 1; // Reset consecutive count
            } 
            else {
                // Append the current character (up to repeatLimit times)
                int useCount = min(repeatLimit, freq[i]);
                result.append(useCount, (char)(i + 'a'));
                freq[i] -= useCount;
                prevChar = i;
                prevCount = useCount;
            }
        }

        return result;
    }
};