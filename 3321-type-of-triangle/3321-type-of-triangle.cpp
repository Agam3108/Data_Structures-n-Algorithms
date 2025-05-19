class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l1 = nums[0];
        int l2 = nums[1];
        int l3 = nums[2];
        if(l1 + l2 <= l3)
        return "none";
        string ans = "";
        if(l1 == l2 && l2 == l3){
            ans = "equilateral";
        }
         if(l1 == l2 && l1 != l3 || l2 == l3 && l2!=l1 || l1 == l3 && l1 != l2){
            ans = "isosceles";
        }
         if(l1 != l2 && l1 !=l3 && l2 != l3 && l2 != l1 && l3 != l2 && l3 != l1){
            ans = "scalene";
        }
        
       
        return ans;
    }
};