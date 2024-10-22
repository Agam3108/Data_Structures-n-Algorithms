class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        map<char,int> mpp;
        mpp.insert({'I',1});
        mpp.insert({'V',5});
        mpp.insert({'X',10});
        mpp.insert({'L',50});
        mpp.insert({'C',100});
        mpp.insert({'D',500});
        mpp.insert({'M',1000});
       /* mpp.insert({"IV",4});
        mpp.insert({"IX",9});
        mpp.insert({"XL",40});
        mpp.insert({"XC",90});
        mpp.insert({"CD",400});
        mpp.insert({"CM",900}); */
        int val = 0;
        for (int i = 0; i < n; i++) {
            
            if (i < n - 1 && mpp[s[i]] < mpp[s[i + 1]]) {
                val -= mpp[s[i]]; 
            } else {
                val += mpp[s[i]]; 
        }
        }
        return val;
    }
};