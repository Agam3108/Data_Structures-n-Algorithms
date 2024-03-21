    int setBits(int N) {
        // Write Your Code here
        int count=0;
        while(N>1){
            count+= N&1;
            N = N>>1;
        }
        if(N==1)
        count+=1;
        return count;
    }