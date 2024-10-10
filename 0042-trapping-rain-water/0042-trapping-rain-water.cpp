class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int Lmax = 0;
        int Rmax = 0;
        int total = 0;
        int r = n-1;
        while(l<r){
            if(height[l] <= height[r]){
                if(Lmax > height[l]){
                   total += Lmax - height[l];
                }
                else
                Lmax = height[l];
                l++ ;
            }
            else{
                if(Rmax > height[r]) {
                    total += Rmax - height[r];
                }
                else
                Rmax = height[r];
                r--;
            }

        }
        return total ;
    }
};