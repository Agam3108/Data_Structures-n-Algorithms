class Solution {
public:
int sum(vector<int> & ans){
    return accumulate(ans.begin(),ans.end(),0);
}
void f(int k,int n,vector<int>& ans,vector<vector<int>>& ds,int num){
    if(k == 0){
        if(sum(ans)==n)
        ds.push_back(ans);
        return ;
    }
    if(num > 9)
    return ;
    ans.push_back(num);
    f(k-1,n,ans,ds,num+1);
    ans.pop_back();
    f(k,n,ans,ds,num+1);

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ds;
        vector<int> res;
        f(k,n,res,ds,1);
       return ds;
    }
};