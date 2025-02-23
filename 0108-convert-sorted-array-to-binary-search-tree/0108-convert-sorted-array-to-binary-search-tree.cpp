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
TreeNode* solve(vector<int> & nums,int low,int high){
  
    if(low<=high){
         int mid = (low + high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(nums,low,mid-1);
        root->right = solve(nums,mid+1,high);
           return root;
    }
    return NULL;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
         return solve(nums,l,r);
    
    }
};