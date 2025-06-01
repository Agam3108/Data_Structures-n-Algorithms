class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=n;j++){
                for(int k = 0;k<=n;k++){
                    if((i+j+k) == n && i<=limit && j<=limit && k<=limit){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};