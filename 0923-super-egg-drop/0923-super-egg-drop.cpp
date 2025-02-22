class Solution {
public:
    int t[101][10001];
    int solve(int k, int n) {
        if (n == 0 || n == 1)
            return n;
        else if (k == 1)
            return n;
        else if (t[k][n] != -1)
            return t[k][n];
            else 
            {  
        int ans = INT_MAX;
        int lo = 1;int hi = n;
           while(lo <= hi){
            int mid = (lo+hi)/2;
            int b = solve(k-1,mid-1);
            int nb = solve(k,n-mid);
            ans = min(ans,1+max(b,nb));
            if(b > nb)
            hi = mid-1;
            else
            lo = mid+1;
           }
           t[k][n] = ans;
        }
        return t[k][n] ;
    }
    int superEggDrop(int k, int n) {
        memset(t, -1, sizeof(t));
        return solve(k, n);
    }
};