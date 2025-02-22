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
        int b = 0;int nb = 0;
           while(lo <= hi){
            int mid = (lo+hi)/2;
            if(t[k-1][mid-1]!=-1)
             b = t[k-1][mid-1];
            else
             b = solve(k-1,mid-1);
            t[k-1][mid-1] = b;
            if(t[k][n-mid]!=-1)
             nb = t[k][n-mid];
            else
             nb = solve(k,n-mid);
            t[k][n-mid] = nb;
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