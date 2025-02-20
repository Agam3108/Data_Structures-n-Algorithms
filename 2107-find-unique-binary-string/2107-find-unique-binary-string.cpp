class Solution {
public:
void generateAllSequences(string s ,int n ,vector<string> &ans){
    if(s.length()==n){
        ans.push_back(s);
        return ;
    }
    generateAllSequences(s+'0',n,ans);
    generateAllSequences(s+'1',n,ans);
}
vector<string> generateSequences(string s,int n){
    vector<string> ans;
    generateAllSequences(s,n,ans);
    return ans;
}
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<string> res = generateSequences("",n);
        string ans ="";
        for(int i = 0;i<res.size();i++){
            auto it = find(nums.begin(),nums.end(),res[i]);
            if(it == nums.end()) {
            ans = res[i];
            break; }
        }
        return ans;
    }
};