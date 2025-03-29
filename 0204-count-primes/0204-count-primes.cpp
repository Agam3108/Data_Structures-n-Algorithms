class Solution {
public:
vector<int> SieveOfEratosthenes(int n)
{
    vector<int> ans;
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
         
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p < n; p++)
    {    if (prime[p])
            ans.push_back(p);
    }
    return ans;
}
    int countPrimes(int n) {
        vector<int> ans = SieveOfEratosthenes(n);
        return ans.size();
    }
};