class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int l1 = A.size();
        unordered_set<int> mp1;
        unordered_set<int> mp2;
        vector<int> res(l1);
        for(int i = 0;i<l1;i++){
            mp1.insert(A[i]);
            mp2.insert(B[i]);
            int count = 0;
            for(const auto it : mp1){
                if(mp2.find(it)!=mp2.end())
                count++;
            }
            res[i] = count;
        }
 return res;
    }
};