string minWindow(string s, string t) {
        int hashArray[256]={0};
        int l=0,r=0,count=0;
        int minLen=1e9;
        int sIndex=-1;
        int n=s.size();
        int m=t.size();
        for(int i=0;i<m;i++){
            hashArray[t[i]]++;
        }
     while(r<n){
        if(hashArray[s[r]]>0){
            count++;
        }
        hashArray[s[r]]--;
        while(count==m && l<=r){
            if(r-l+1<minLen){
            minLen=r-l+1;
            sIndex=l;
            
            }
            hashArray[s[l]]++;
            if(hashArray[s[l]]>0)
            count--;
            l++;
        }
        r++;
     }
     return sIndex==-1?"":s.substr(sIndex,minLen);
    }