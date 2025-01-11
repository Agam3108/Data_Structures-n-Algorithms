class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n==k)
        return true;
        if(n<k)
        return false;
        map<char,int> mpp;
        for(const char c : s)
        mpp[c]++;
        int count = 0;
        for(const auto it: mpp){
            if(it.second % 2 !=0)
            count++;
            if(count > k)
            return false;


        }
return true;
    }
};