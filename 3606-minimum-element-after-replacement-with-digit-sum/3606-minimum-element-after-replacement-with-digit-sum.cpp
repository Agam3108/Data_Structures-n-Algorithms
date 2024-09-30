class Solution {
public:
int sumOfDigits(int num){
    int sum = 0;
    while(num!=0){
        int d = num%10;
        num = num/10;
        sum+= d;
    }
    return sum;
}
    int minElement(vector<int>& nums) {
       int n = nums.size();
       for(int i = 0;i<n;i++){
        nums[i] = sumOfDigits(nums[i]);
    }
    sort(nums.begin(),nums.end());
    return nums[0];
    }
};