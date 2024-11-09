class Solution {
public:
int productDigit(int n){
    int prod = 1;
    while(n!=0){
        int d = n%10;
        prod *= d;
        n /= 10;
    }
    return prod ;
}
    int smallestNumber(int n, int t) {
        if(productDigit(n)%t==0)
        return n;
        int temp = n;
        int ans ;
        while(temp<=100){
            if(productDigit(temp)%t==0)
             {
                ans = temp;
                break;
             }
            else
            temp++;
        }
        return ans;
    }
};