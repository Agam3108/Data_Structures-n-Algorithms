class Solution {
public:
    int minSwaps(string s) {
         int balance = 0;    
        int swaps = 0;      // Count of swaps needed
        int maxNegative = 0;
        
        for (char c : s) {
            if (c == '[') {
                balance++;
            } else {
                balance--;
            }
            
          
            maxNegative = min(maxNegative, balance);
        }
        
        swaps = (-maxNegative + 1) / 2;
        return swaps;
    }
};