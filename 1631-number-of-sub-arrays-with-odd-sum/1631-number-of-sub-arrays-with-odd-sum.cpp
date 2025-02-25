class Solution {
public:
const int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();
        int odd = 0, even = 1; 
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum % 2 == 0) {
                cnt += odd;  
                even++;      
            } else {
                cnt += even; 
                odd++;
            }
            cnt %= mod;
        }
        return cnt%mod;
    }
};