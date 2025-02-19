class Solution {
public:

void generateAllStrings(int n,string curr,vector<string> &res){
    if(curr.length()==n ) {
        res.push_back(curr);
        return ;
    }
     for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) { // Ensure no consecutive same letters
                generateAllStrings(n, curr + ch, res);
            }
        }
}
vector<string> generateStrings(int n){
     vector<string> result;
    generateAllStrings(n, "", result);
    return result;
}
    string getHappyString(int n, int k) {
        vector<string> ans;
        ans = generateStrings(n);
        string res ;
        res = (ans.size() < k) ? "" : ans[k-1]; 
       return res;
    }
};