  int characterReplacement(string s, int k) {
        int l=0,r=0;
        int maxLen=0,maxFreq=0;
        int n=s.size();
        int hash[26]={0};
        while(r<n){
            hash[s[r]-'A']++;
            maxFreq=max(maxFreq,hash[s[r]-'A']);
            if((r-l+1)-maxFreq>k){
                hash[s[l]-'A']--;
                maxFreq=0;
                l++;
            }
            if((r-l+1)-maxFreq<=k)
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }