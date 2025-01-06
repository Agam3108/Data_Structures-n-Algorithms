class Solution {
public:
    long long findGCD(int a, int b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }
    
    long long findLCM(int a, int b) {
        return (1LL * a / findGCD(a, b)) * b; 
    }
    
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long lcm = nums[i];
            long long gcd = nums[i];
            
            for (int j = i; j < n; j++) {
                if (prod > LLONG_MAX / nums[j]) {
                    break;
                }
                prod *= nums[j];
                lcm = findLCM(lcm, nums[j]);
                gcd = findGCD(gcd, nums[j]);
                
                if (prod == lcm * gcd)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
