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
     int widthOfBinaryTree(TreeNode* root) {

        // Your code here
        if(!root)
        return 0;
        unsigned int ans=0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root,0});
        while(!q.empty()){
            unsigned int min=q.front().second;
            unsigned int first,last;
             unsigned int n=q.size();
            for(int i=0;i<n;i++){
                unsigned int curr=q.front().second-min;
                    
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)
                first=curr;
                if(i==n-1)
                last=curr;
                if(node->left)
                q.push({node->left,(long long)curr*2+1});
                if(node->right)
                q.push({node->right,(long long)curr*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};