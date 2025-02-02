class Solution {
public:
bool isSortedArr(vector<int> &arr){
    for(int i = 0;i<arr.size()-1;i++){
        if(arr[i+1]<arr[i])
        return false;
    }
    return true;
}
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(isSortedArr(nums))
        return true;
        int k = n-1;
        while(k--){
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+1);
        reverse(nums.begin()+1,nums.end());
        if(isSortedArr(nums))
        return true;
        }
        return false;
    }
};