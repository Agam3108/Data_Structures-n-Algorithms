class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int k=n-1;
        bool ans =false;
        if(s==goal)
        return true;
        for(int i=0;i<k;i++){
            char c = s[0];
            for(int j=0;j<n-1;j++){
                s[j]=s[j+1];
            }
            s[n-1]=c;
            if(s==goal)
            ans = true;
        }
        return ans;
    }
};