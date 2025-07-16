class Solution {
public:
    int maximumLength(vector<int>& nums) {
          int count_even = 0;
    int count_odd = 0;
    int max_length_even = 0;
    int max_length_odd = 0;
    int current_length_even = 0;
    int current_length_odd = 0;

 
    for (int num : nums) {
        if (num % 2 == 0) {
            count_even++;
            max_length_even = max_length_odd + 1;
        } else {
            count_odd++;
             max_length_odd = max_length_even + 1;
        }
    }
    return max(max(count_even,count_odd), max(max_length_odd,max_length_even));
       
    }
};