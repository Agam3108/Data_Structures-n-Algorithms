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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr)
        return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> currLevel;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                currLevel.push_back(node);
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
            }
            if(level%2==1){
                int left=0;int right=currLevel.size()-1;
                while(left<right){
                    swap(currLevel[left]->val,currLevel[right]->val);
                    left++;
                    right--;
                }
            }
         level++;
        }
       return root;
    }
};