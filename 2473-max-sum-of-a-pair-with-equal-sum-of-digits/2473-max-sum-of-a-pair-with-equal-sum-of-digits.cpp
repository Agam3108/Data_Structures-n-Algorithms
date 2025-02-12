class Solution {
public:
    int sumOfDigits(int num){
        int sum = 0;
        while(num!=0){
            int d = num%10;
            num/= 10;
            sum += d;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
       vector<pair<int,int>> sumValue;
       int n = nums.size();
       for(int i = 0;i<n;i++){
        sumValue.push_back({sumOfDigits(nums[i]),nums[i]});
       }
       sort(sumValue.begin(),sumValue.end());
       int maxSum = -1;
       for(int i = 1;i<sumValue.size();i++){
        int currentSum = sumValue[i].first;
        int prevSum = sumValue[i-1].first;
        if(currentSum == prevSum){
            int sum = sumValue[i].second + sumValue[i-1].second;
            maxSum = max(maxSum,sum);
        }
       }
       return maxSum;
    }
};