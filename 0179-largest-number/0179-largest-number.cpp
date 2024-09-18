class Solution {
public:
static bool compare(int a, int b) {
    string strA = to_string(a);
    string strB = to_string(b);
    return strA + strB > strB + strA;
}

    string largestNumber(vector<int>& nums) {
        int n = nums.size();
       sort(nums.begin(),nums.end(),compare);
       if(nums[0]==0)
       return "0";
        
 
      string ans = "";
      for(int i =0;i<n;i++){
        ans += to_string(nums[i]);
      }
      
      return ans;
    }
};