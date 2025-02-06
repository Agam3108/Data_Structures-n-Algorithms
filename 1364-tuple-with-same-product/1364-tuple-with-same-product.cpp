class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int countPosSubs = 0;
        unordered_map<int,int> productCount ;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
               long long int prod = nums[i] * nums[j];
                countPosSubs += productCount[prod];
                productCount[prod]++;
            }
        }
        return countPosSubs*8 ;
    }
};