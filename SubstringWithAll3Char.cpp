 int numberOfSubstrings(string s) {
       int lastSeen[3]={-1,-1,-1};
       int count=0;
       for(int i=0;i<s.size();i++){
        lastSeen[s[i]-'a']=i;
        int minLastPosition=(1+min(lastSeen[0],min(lastSeen[1],lastSeen[2])));
        count+=minLastPosition;
       }
       return count;
    }
    