/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
       
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
             vector<int> level;
             for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
                level.push_back(node->val);
             }
             ans.push_back(level);
        }
        return ans;

    }
    int minimumSwapsToSort(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }
        sort(vec.begin(), vec.end());
        vector<bool> visited(n, false);
        int swaps = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] || vec[i].second == i) {
                continue;
            }

            int cycle_size = 0;
            int j = i;
            while(!visited[j]) {
                visited[j] = true;
                j = vec[j].second;
                cycle_size++;
            }
            if(cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        
       vector<vector<int>> res = levelOrder(root);
        int n = res.size();
        vector<int> countArray;

        for(int i = 0; i < n; i++) {
            countArray.push_back(minimumSwapsToSort(res[i]));
        }

        int totalOperations = 0;
        for(int count : countArray) {
            totalOperations += count;
        }

        return totalOperations;
    }
};