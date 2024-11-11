class Solution {
public:
vector<int> SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
      vector<int> res;
  for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <n; p++) {
        if (prime[p])
           res.push_back(p);
    }
    return res;
}
 
    bool primeSubOperation(vector<int>& nums) {
          int n = nums.size();
        vector<int> primes = SieveOfEratosthenes(1000); 
        
        for (int i = 0; i < n; i++) {
            bool valid = false;
            for (int j = primes.size() - 1; j >= 0; j--) {
                if (primes[j] < nums[i] && (i == 0 || nums[i] - primes[j] > nums[i - 1])) {
                    nums[i] -= primes[j];
                    valid = true;
                    break;
                }
            }
            if (!valid && i > 0 && nums[i] <= nums[i - 1]) {
                return false; 
            }
        }

        return true;
    }
};