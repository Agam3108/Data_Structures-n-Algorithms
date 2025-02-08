class Solution {
public:
void sortSubarrays(std::vector<int>& a, const std::vector<int>& b) {
    int n = a.size();
    int start = 0;
    while (start < n) {
        int end = start;
        while (end < n && b[end] == b[start]) {
            end++;
        }
        std::sort(a.begin() + start, a.begin() + end);
        start = end;
    }
}
string DecimalToBinary(int num)
{
    string str;
      while(num){
      if(num & 1) 
        str+='1';
      else 
        str+='0';
      num>>=1; 
    }    
      return str;
}
int countBits(string s){
    int count = 0;
    int n = s.length();
    for(int i = 0;i<n;i++){
        if(s[i]=='1')
        count++;
    }
    return count;
}
bool isSorted(vector<int> &nums){
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(),temp.end());
    for(int i = 0;i<n;i++){
        if(temp[i]!=nums[i])
        {
            return false;
            break;
        }
        else
        continue;
    }
    return true;
}
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        if(isSorted(nums))
        return true;
        vector<int> countSetBits;
        for(int i=0;i<n;i++){
          string s = DecimalToBinary(nums[i]);
          countSetBits.push_back(countBits(s));
        }
        sortSubarrays(nums,countSetBits);
        if(isSorted(nums))
        return true;
        return false;
    }
};