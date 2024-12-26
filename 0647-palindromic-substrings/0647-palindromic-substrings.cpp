class Solution {
public:
bool isPalindromic(string s ,int left,int right){
    while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
}

    int countSubstrings(string s) {
       int n = s.size();
      // vector<string> res;
      int count = 0;
       for(int i =0;i<n;i++){
        for(int j = i;j<n;j++){
             if(isPalindromic(s,i,j)){
           // string str = s.substr(i,j-i+1);
             //res.push_back(str);4
             count++;
           }
        }
       }
       return count;
    }
};