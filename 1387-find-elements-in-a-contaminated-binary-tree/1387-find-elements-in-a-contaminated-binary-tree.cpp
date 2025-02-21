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
class FindElements {
public:
unordered_set<int> seen;
    FindElements(TreeNode* root) {  
      bfs(root);
    }
    
    bool find(int target) {
        if(seen.find(target)==seen.end())
        return false;
        return true;
    }
    void bfs(TreeNode* root){
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        seen.insert(root->val);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            int x = curr->val;
            if(curr->left!=NULL){
                curr->left->val = 2*x+1;
                seen.insert(curr->left->val);
                q.push(curr->left);
            }
            if(curr->right !=NULL){
                curr->right->val = 2*x+2;
                seen.insert(curr->right->val);
                q.push(curr->right);
            }
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */