class Solution {
public:
long long calc(vector<int> & arr, vector<int>& brr){
    int n = arr.size();
     vector<long long> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(arr[i] - brr[i]);
        }
        long long currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += diff[i]; 
        }
        return currentSum;
}
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
       int n = arr.size();
    
        long long initialCost = calc(arr,brr);
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        long long optimalCost = calc(arr,brr)+k;
        return min(initialCost,optimalCost); 
    }
};