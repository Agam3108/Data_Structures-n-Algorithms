class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.length();
        int rem = n%k ;
        for(int i = 0; i<n-rem;i=i+k){
            string str = s.substr(i,k);
            res.push_back(str);
        }
        if(rem!=0){
        string last = s.substr(n-rem,rem);
        while(last.size() != k){
            last += fill ;
        }
        res.push_back(last);
        }
        return res;
    }
};