class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)
        return 1;
        long long ans = 1 + (long long)2*n*(n-1) ;
        return ans;
    }
};