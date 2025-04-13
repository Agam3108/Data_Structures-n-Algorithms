class Solution {
public:
const int mod = 1e9+7;
long long modPow(long long base, long long exp) {
        if (exp == 0) return 1;
        if (exp % 2 == 0) {
            long long half = modPow(base, exp / 2);
            return (half * half) % mod;
        } else {
            return (base * modPow(base, exp - 1)) % mod;
        }
    }
    int countGoodNumbers(long long n) {
       long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        return (modPow(5, evenCount) * modPow(4, oddCount)) % mod;
    }
};