class FindSumPairs {
public:
vector<int> n1;
vector<int> n2;
unordered_map<int,int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(int num2 : nums2){
            m[num2]++;
        }
    }
    
    void add(int index, int val) {
        m[n2[index]]--;
        n2[index] += val;
        m[n2[index]]++;
    }

    

    int count(int tot) {
        int c = 0;
        for(int x : n1){
            c += m[tot-x];
        }
    
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */