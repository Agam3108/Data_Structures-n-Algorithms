class Solution {
public:
int sumOfDigits(int num){
    int sum = 0;
    while(num!=0){
        int d = num%10;
        sum += d;
        num/= 10;
    }
    return sum;
}
int countDigits(int num){
    int c = 0;
    while(num!=0){
        int d = num%10;
        num/= 10;
        c++;
    }
    return c;
}
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low;i<=high;i++){
             if(countDigits(i)%2 == 0){
                
                string str = to_string(i);
                int len = str.size();
                string s1 = str.substr(0,len/2);
                string s2 = str.substr(len/2,len/2);
                int sum1 = sumOfDigits(stoi(s1));
                int sum2 = sumOfDigits(stoi(s2));
                if(sum1 == sum2)
                count++;
             }
             else
             continue;
        }
        return count;
    }
};