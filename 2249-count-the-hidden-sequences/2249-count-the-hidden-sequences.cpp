class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
         int n = differences.size();
         long long prefix = 0;
         long long min_offset = 0;
         long long max_offset = 0;
         for(const auto difference : differences){
            prefix += difference ;
            min_offset = min(prefix,min_offset);
            max_offset = max(prefix,max_offset);
         }
          
        long long min_x = lower - min_offset ;
        long long max_x = upper - max_offset;
        
        if (min_x > max_x) return 0;
        return max_x - min_x + 1;

    }
};