class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n =  s1.length();
        int m = s2.length();
        if(n>m)
        return false;
        unordered_map<char,int> map1;
        for(int i = 0;i<n;i++){
            map1[s1[i]]++;
        }
        int slow = 0;
        int fast = n-1 ;
        unordered_map<char,int> map2;
        while(slow <= fast && fast<m){
           string s = s2.substr(slow,fast-slow+1);
           for(int i = 0;i<s.size();i++){
            map2[s[i]]++;
           }
           if(map1 == map2){
            return true;
            break;
           }
           slow++;
           fast++;
           map2.clear();
        }
        return false;
    }
};