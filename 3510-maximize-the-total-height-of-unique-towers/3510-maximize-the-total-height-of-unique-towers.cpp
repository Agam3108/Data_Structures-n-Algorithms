class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        
        sort(maximumHeight.rbegin(),maximumHeight.rend());
        for(int i = 1 ;i<n;i++){
          maximumHeight[i] =min(maximumHeight[i-1]-1,maximumHeight[i]);
        }
        if(maximumHeight[n-1] <= 0)
        return -1 ;
        
       long long sum = 0;
       for(int i =0;i<n;i++){
        sum = sum +(long long)maximumHeight[i];
       }
       return sum;
    }
};