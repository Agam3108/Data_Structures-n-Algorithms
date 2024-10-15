class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int l=0,r=0;
        long long count=0;
       while(r<n){
        while (l < n && s[l] == '0') l++;
        
        while (r < n && (r <= l || s[r] == '1')) r++;
        if (l < n && r < n) {
            count += (r - l);
            swap(s[l], s[r]);
            l++;
            r++;
        }
       }
        return count;
    }
};