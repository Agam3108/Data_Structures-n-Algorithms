
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
      int n = nums.size();
      if(n < 3)
      return n;
      return pow(2,int(log2(n))+1);
    }
};