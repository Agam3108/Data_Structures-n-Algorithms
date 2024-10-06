class Solution {
public:
    string dectobinary(int num) {
        string str;
        while(num) {
            if(num & 1) // 1
                str += '1';
            else // 0
                str += '0';
            num >>= 1;
        }
        reverse(str.begin(), str.end());  // to get the correct binary representation
        return str.empty() ? "0" : str;
    }

    long long binarytodec(string n) {
        long long dec_value = 0;
        long long base = 1;
        int len = n.length();
        for (int i = len - 1; i >= 0; i--) {
            if (n[i] == '1')
                dec_value += base;
            base *= 2;
        }
        return dec_value;
    }

    void permutations(vector<int> &arr, vector<vector<int>> &res, int idx) {
        if (idx == arr.size() - 1) {
            res.push_back(arr);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            swap(arr[idx], arr[i]);
            permutations(arr, res, idx + 1);
            swap(arr[idx], arr[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, ans, 0);
        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long maxi = LLONG_MIN;
        vector<vector<int>> res = permute(nums);

        for(int i = 0; i < res.size(); i++) {
            string ans = "";  
            for(int j = 0; j < res[0].size(); j++) {
                ans += dectobinary(res[i][j]);
            }
            maxi = max(maxi, binarytodec(ans));
        }
        return (int)maxi;
    }
};
