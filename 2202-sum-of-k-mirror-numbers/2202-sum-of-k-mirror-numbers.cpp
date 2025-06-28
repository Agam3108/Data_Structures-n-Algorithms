class Solution {
public:
long generatePalindrome(long len, bool odd){
   long x  = len;
   if(odd){
     x/= 10;
   }
   while(x > 0){
     len = len*10 + x%10;
     x/=10;
   }
   return len ;
}
bool isPalindromeBaseK(long num,int base){
    long rev = 0;
    long copy = num;
    while(num != 0){
        rev = rev*base + num % base ;
        num/= base;
    }
    return (rev == copy);
}
    long long kMirror(int k, int n) {
        long long sum = 0;
        for(long len = 1;n>0;len *= 10){
        for(long i = len;n>0 && i<len*10;i++){
            long p = generatePalindrome(i,true);
            if(isPalindromeBaseK(p,k)) {
            sum += p;
            n--;
            }
          }
          for(long i = len;n>0 && i<len*10;i++){
              long p = generatePalindrome(i,false);
            if(isPalindromeBaseK(p,k)) {
            sum += p;
            n--;
          }
        }
        }
        return sum;
    }
};