

class Solution {
public:
    // Function to check if a character is a vowel
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    // Function to update the bitmask for vowels
    void updateVowelBitmask(char ch, int& vowelMask) {
        if (ch == 'a') vowelMask |= (1 << 0);  // Set 0th bit for 'a'
        else if (ch == 'e') vowelMask |= (1 << 1);  // Set 1st bit for 'e'
        else if (ch == 'i') vowelMask |= (1 << 2);  // Set 2nd bit for 'i'
        else if (ch == 'o') vowelMask |= (1 << 3);  // Set 3rd bit for 'o'
        else if (ch == 'u') vowelMask |= (1 << 4);  // Set 4th bit for 'u'
    }

    // Function to check if a character is a consonant
    bool isNotVowel(char ch) {
        return !isVowel(ch);
    }

    // Main function to count substrings with all vowels and k consonants
    int countOfSubstrings(const string& word, int k) {
        int n = word.length();
        int count = 0;

        // Iterate through all starting points of substrings
        for (int i = 0; i < n; i++) {
            int consonantCount = 0;
            int vowelMask = 0;  // Bitmask to track which vowels are present

            // Expand the substring from i to j
            for (int j = i; j < n; j++) {
                // Update the consonant count for the new character
                if (isNotVowel(word[j])) {
                    consonantCount++;
                } else {
                    // Update the vowel bitmask for the new character
                    updateVowelBitmask(word[j], vowelMask);
                }

                // Check if the substring from i to j has k consonants and all vowels
                if (consonantCount == k && vowelMask == 31) { // 31 is binary 11111, meaning all vowels present
                    count++;
                }
            }
        }

        return count;
    }
};

