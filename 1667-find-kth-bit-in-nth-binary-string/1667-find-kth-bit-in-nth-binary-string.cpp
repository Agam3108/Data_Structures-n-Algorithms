class Solution {
public:
    string reversestr(string s){
        string str;
        for(int i = s.length() - 1; i >= 0; i--){
            str.push_back(s[i]);
        }
        return str;
    }

    string inversestr(string s){
        for(int i = 0; i < s.length(); i++){
          
            if(s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }

    char findKthBit(int n, int k) {
        vector<string> ss(n);
        ss[0] = "0"; 
        
        for(int i = 1; i < n; i++){
            ss[i] = ss[i - 1] + "1" + reversestr(inversestr(ss[i - 1]));
        }
        
        return ss[n - 1][k - 1]; 
    }
};
