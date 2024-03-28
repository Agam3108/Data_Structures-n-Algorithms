  long long divide(long long dividend, long long divisor) 
    {
        //code here
        if(dividend==divisor)
        return 1;
        bool sign=true;
        if(dividend>=0 && divisor<0)
        sign=false;
        if(dividend<0 && divisor>=0)
        sign=false;
        long long n=abs(dividend);
        long long d=abs(divisor);
        long long quotient=0;
        while(n>=d){
            int count=0;
            while(n>=(d<<(count+1))){
                count++;
            }
            quotient+=(1<<count);
            n=n-(d<<count);
        }
        if(quotient ==(1<<31) && sign==true)
        return LLONG_MAX;
        if(quotient == (1<<31) && sign == false)
        return LLONG_MIN;
        return sign?quotient:-quotient ;
        
    }