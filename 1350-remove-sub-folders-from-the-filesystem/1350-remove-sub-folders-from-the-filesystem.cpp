class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        
        for(int i = 1;i<n;i++){
            string s = ans.back();
            s += '/';
            int m = s.size();
            if(folder[i].compare(0,m,s)!=0)
            ans.push_back(folder[i]);
        }
        return ans;
    }
};