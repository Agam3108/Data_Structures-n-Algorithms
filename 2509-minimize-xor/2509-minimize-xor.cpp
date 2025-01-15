class Solution {
public:
    string numToBinary(int num) {
        string str;
        while (num) {
            if (num & 1)
                str += '1';
            else
                str += '0';
            num >>= 1;
        }
        return str;
    }
    int countSetBits(int num) {
        string str = numToBinary(num);
        int count = 0;
        for (char c : str) {
            if (c == '1')
                count++;
        }
        return count;
    }
    int minimizeXor(int num1, int num2) {
        int targetSetBits = countSetBits(num2);
        int result = 0;
        for (int i = 31; i >= 0 && targetSetBits > 0; --i) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                targetSetBits--;
            }
        }
        for (int i = 0; i < 32 && targetSetBits > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                targetSetBits--;
            }
        }

        return result;
    }
};