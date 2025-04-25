class Solution {
public:
int digitSum(int num){
    return num == 0 ? 0 : num % 10 + digitSum(num/10) ;
}
    int countLargestGroup(int n) {
        int count = 0;
        int maxi = 0 ;
        vector<int> sums(37);
        for(int i = 1;i<=n;i++){
            sums[digitSum(i)]++;
        }
        for(int sum : sums){
            if(sum > maxi)
           { maxi = sum;
            count = 1; }
            else if(sum == maxi)
            count++;
        }
 return count;
    }
};