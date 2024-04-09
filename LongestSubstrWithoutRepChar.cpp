 int lengthOfLongestSubstring(string s) {
       vector<int> hashArray(256,-1);
        int l=0,r=0, maxLen=0;
        if(s.empty())
        return 0;
        while(r<s.size()){
            if(hashArray[s[r]]!=-1){
                //if(hashArray[s[r]]>=l){
                    l=max(hashArray[s[r]]+1,l);
                
            }
            int len=r-l+1;
            maxLen=max(len,maxLen);
            hashArray[s[r]]=r;
            r++;
        }
        return maxLen;
    }