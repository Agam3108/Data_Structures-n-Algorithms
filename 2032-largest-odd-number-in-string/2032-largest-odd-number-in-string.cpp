class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
       // long long int s = stoll(num);
       // if(s%2==1)
       // return num;
        int countEvens = 0;
        for(char c: num){
            if((c-'0')%2==0)
            countEvens++;
        }
        if(countEvens == n)
        return "";
        int r = n-1;
        int cnt = 0;
        while(num[r]%2 !=1 && r>=0){
            cnt++;
            r--;
        }
      string str =  num.substr(0,n-cnt);
      return str;
    }
};